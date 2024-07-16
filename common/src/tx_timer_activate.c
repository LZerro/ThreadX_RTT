#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_timer.h"

UINT  _tx_timer_activate(TX_TIMER *timer_ptr)
{
    RT_ASSERT(timer_ptr);

    if(timer_ptr->TIME_START_FLAG == TX_TIMER_NEED_RESTART)
    {
        rt_timer_start((rt_timer_t)timer_ptr);
        rt_timer_control(timer_ptr, RT_TIMER_CTRL_SET_TIME, timer_ptr->tx_timer_internal_re_initialize_ticks);
    }
    else
    {
        rt_timer_start((rt_timer_t)timer_ptr);
    }

    return TX_SUCCESS;
}
