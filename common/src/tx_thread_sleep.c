#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_sleep(ULONG timer_ticks)
{
    rt_err_t Res = rt_thread_delay((rt_tick_t)timer_ticks);
    if(Res != RT_EOK)
    {
        return TX_CALLER_ERROR;
    }
    return TX_SUCCESS;
}