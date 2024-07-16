#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_mutex_info_get(TX_MUTEX *mutex_ptr, CHAR **name, ULONG *count, TX_THREAD **owner,
                         TX_THREAD **first_suspended, ULONG *suspended_count,
                         TX_MUTEX **next_mutex)
{
    RT_ASSERT(mutex_ptr && name && count && owner && first_suspended && suspended_count && next_mutex);

    rt_list_t *n;
    rt_mutex_t Mutex_temp_ptr = (rt_mutex_t)mutex_ptr;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = Mutex_temp_ptr->parent.parent.name;

    *count = Mutex_temp_ptr->hold;

    *owner = Mutex_temp_ptr->owner;

    *first_suspended = Mutex_temp_ptr->parent.suspend_thread.next;

    for (n = Mutex_temp_ptr->parent.suspend_thread.next; n != &(Mutex_temp_ptr->parent.suspend_thread); n = n->next, suspended_count++);

    *next_mutex = TX_NULL;

    rt_hw_interrupt_enable( level );
}
