#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_delete(TX_THREAD *thread_ptr)
{
    rt_err_t Res = rt_thread_t((struct rt_thread *)thread_ptr);
    if(Res == RT_EOK)
    {
        return TX_SUCCESS;
    }
    else
    {
        return TX_DELETE_ERROR;
    }
}