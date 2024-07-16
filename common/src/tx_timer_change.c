#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_timer.h"

UINT  _tx_timer_change(TX_TIMER *timer_ptr, ULONG initial_ticks, ULONG reschedule_ticks)
{
    RT_ASSERT(timer_ptr);

    if(((rt_timer_t)timer_ptr)->parent.flag != RT_TIMER_FLAG_ACTIVATED)
    {
        rt_timer_control((rt_timer_t)timer_ptr, RT_TIMER_CTRL_SET_TIME, initial_ticks);
        if(reschedule_ticks == 0)
        {
            timer_ptr->TIME_START_FLAG == TX_TIMER_ONLY_ONCE;
            rt_timer_control((rt_timer_t)timer_ptr, timer_ptr->TIME_START_FLAG, RT_NULL);
        }
        else
        {
            timer_ptr->TIME_START_FLAG == TX_TIMER_NEED_RESTART;
            timer_ptr->tx_timer_internal_re_initialize_ticks = reschedule_ticks;
            rt_timer_control((rt_timer_t)timer_ptr, timer_ptr->TIME_START_FLAG, RT_NULL);
        }
    }
}