#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_delete(TX_THREAD *thread_ptr)
{
    RT_ASSERT(thread_ptr);

    rt_thread_t Thread_temp_ptr = (rt_thread_t)thread_ptr;
    rt_err_t Res = rt_thread_delete(Thread_temp_ptr);
    if(Res == RT_EOK)
    {
        return TX_SUCCESS;
    }
    else
    {
        return TX_DELETE_ERROR;
    }
}