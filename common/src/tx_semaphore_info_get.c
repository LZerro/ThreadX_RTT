#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_semaphore_info_get(TX_SEMAPHORE *semaphore_ptr, CHAR **name, ULONG *current_value,
                             TX_THREAD **first_suspended, ULONG *suspended_count,
                             TX_SEMAPHORE **next_semaphore)
{
    RT_ASSERT(semaphore_ptr && name && current_value && first_suspended && suspended_count && next_semaphore);

    rt_list_t *n;
    rt_sem_t Sem_temp_ptr = (rt_sem_t)semaphore_ptr;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = Sem_temp_ptr->parent.parent.name;

    *current_value = Sem_temp_ptr->value;

    *first_suspended = Sem_temp_ptr->parent.suspend_thread.next;

    for (n = Sem_temp_ptr->parent.suspend_thread.next; n != &(Sem_temp_ptr->parent.suspend_thread); n = n->next, suspended_count++);

    *next_semaphore = TX_NULL;

    rt_hw_interrupt_enable( level );
}
