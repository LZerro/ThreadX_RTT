#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_queue_info_get(TX_QUEUE *queue_ptr, CHAR **name, ULONG *enqueued, ULONG *available_storage,
                         TX_THREAD **first_suspended, ULONG *suspended_count, TX_QUEUE **next_queue)
{
    RT_ASSERT(mutex_ptr && name && enqueued && available_storage && first_suspended && suspended_count && next_queue);

    struct rt_list_node *n;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = queue_ptr->parent.parent.name;

    *enqueued = queue_ptr->entry;

    *available_storage = queue_ptr->max_msgs - queue_ptr->entry;

    *first_suspended = mutex_ptr->parent.suspend_thread.next;

    for (n = mutex_ptr->parent.suspend_thread.next; n != mutex_ptr->parent.suspend_thread; n = n->next, suspended_count++);

    *next_queue = TX_NULL;

    rt_hw_interrupt_enable( level );
}