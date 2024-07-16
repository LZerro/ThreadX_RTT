#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_terminate(TX_THREAD *thread_ptr)
{
    rt_thread_t Thread_temp_ptr = (rt_thread_t)thread_ptr;
    if(rt_thread_close(Thread_temp_ptr) == RT_EOK)
    {
        return TX_SUCCESS;
    }
}
