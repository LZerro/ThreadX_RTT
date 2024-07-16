#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_queue_info_get(TX_QUEUE *queue_ptr, CHAR **name, ULONG *enqueued, ULONG *available_storage,
                         TX_THREAD **first_suspended, ULONG *suspended_count, TX_QUEUE **next_queue)
{
    RT_ASSERT(queue_ptr && name && enqueued && available_storage && first_suspended && suspended_count && next_queue);

    rt_list_t *n;
    rt_mq_t Queue_temp_ptr = (rt_mq_t)queue_ptr;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = Queue_temp_ptr->parent.parent.name;

    *enqueued = Queue_temp_ptr->entry;

    *available_storage = Queue_temp_ptr->max_msgs - Queue_temp_ptr->entry;

    *first_suspended = Queue_temp_ptr->parent.suspend_thread.next;

    for (n = Queue_temp_ptr->parent.suspend_thread.next; n != &(Queue_temp_ptr->parent.suspend_thread); n = n->next, suspended_count++);

    *next_queue = TX_NULL;

    rt_hw_interrupt_enable( level );
}