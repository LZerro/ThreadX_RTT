#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_queue_front_send(TX_QUEUE *queue_ptr, VOID *source_ptr, ULONG wait_option)
{
    if(rt_mq_urgent((rt_mq_t)queue_ptr, source_ptr, sizeof(source_ptr)) == RT_EOK)
    {
        return  TX_SUCCESS;
    }
    return TX_QUEUE_FULL;
}
