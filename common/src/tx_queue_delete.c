#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_queue_delete(TX_QUEUE *queue_ptr)
{
    RT_ASSERT(queue_ptr);
    rt_mq_detach(queue_ptr);
    return TX_SUCCESS;
}
