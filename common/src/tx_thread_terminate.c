#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_terminate(TX_THREAD *thread_ptr)
{
    if(rt_thread_close(rt_thread_t)thread_ptr) == RT_EOK)
    {
        return TX_SUCCESS;
    }
}
