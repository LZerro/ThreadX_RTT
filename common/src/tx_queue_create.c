#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_queue_create(TX_QUEUE *queue_ptr, CHAR *name_ptr, UINT message_size,
                       VOID *queue_start, ULONG queue_size)
{
    RT_ASSERT(queue_ptr);
    RT_ASSERT(name_ptr && queue_start);
    rt_mq_init((rt_mq_t)queue_ptr, name_ptr, queue_start, message_size, queue_size, RT_IPC_FLAG_PRIO);
    return TX_SUCCESS;
}