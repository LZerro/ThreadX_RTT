#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_queue_receive(TX_QUEUE *queue_ptr, VOID *destination_ptr, ULONG wait_option)
{
    RT_ASSERT(queue_ptr);

    if(rt_mq_recv((rt_mq_t)queue_ptr, destination_ptr, sizeof(destination_ptr), wait_option) == RT_EOK)
    {
        return TX_SUCCESS;
    }
    return  TX_QUEUE_EMPTY;
}
