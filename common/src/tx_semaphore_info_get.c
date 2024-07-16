#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_semaphore_info_get(TX_SEMAPHORE *semaphore_ptr, CHAR **name, ULONG *current_value,
                             TX_THREAD **first_suspended, ULONG *suspended_count,
                             TX_SEMAPHORE **next_semaphore)
{
    RT_ASSERT(semaphore_ptr && name && current_value && first_suspended && suspended_count && next_semaphore);

    struct rt_list_node *n;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = semaphore_ptr->parent.parent.name;

    *current_value = semaphore_ptr->value;

    *first_suspended = mutex_ptr->parent.suspend_thread.next;

    for (n = mutex_ptr->parent.suspend_thread.next; n != mutex_ptr->parent.suspend_thread; n = n->next, suspended_count++);

    *next_semaphore = TX_NULL;

    rt_hw_interrupt_enable( level );
}
