#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_mutex_info_get(TX_MUTEX *mutex_ptr, CHAR **name, ULONG *count, TX_THREAD **owner,
                         TX_THREAD **first_suspended, ULONG *suspended_count,
                         TX_MUTEX **next_mutex)
{
    RT_ASSERT(mutex_ptr && name && count && owner && first_suspended && suspended_count && next_mutex);

    struct rt_list_node *n;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = mutex_ptr->parent.parent.name;

    *count = mutex_ptr->hold;

    *owner = mutex_ptr->owner;

    *first_suspended = mutex_ptr->parent.suspend_thread.next;

    for (n = mutex_ptr->parent.suspend_thread.next; n != mutex_ptr->parent.suspend_thread; n = n->next, suspended_count++);

    *next_mutex = TX_NULL;

    rt_hw_interrupt_enable( level );
}
