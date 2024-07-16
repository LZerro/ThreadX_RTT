#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_timer.h"

UINT  _tx_timer_create(TX_TIMER *timer_ptr, CHAR *name_ptr,
                       VOID (*expiration_function)(ULONG id), ULONG expiration_input,
                       ULONG initial_ticks, ULONG reschedule_ticks, UINT auto_activate)
{
    if(reschedule_ticks != 0)
    {
        timer_ptr->TIME_START_FLAG = TX_TIMER_NEED_RESTART;
        timer_ptr->tx_timer_internal_re_initialize_ticks = reschedule_ticks;
    }
    else
    {
        timer_ptr->TIME_START_FLAG = TX_TIMER_ONLY_ONCE;
    }

    rt_timer_init((struct rt_timer*)timer_ptr, name_ptr,
                  (thread_entry_func)expiration_function, (void*)expiration_input,
                  initial_ticks, timer_ptr->TIME_START_FLAG );
    }

    if(auto_activate == TX_AUTO_ACTIVATE)
    {
        rt_timer_start((rt_timer_t)timer_ptr);
        if(timer_ptr->TIME_START_FLAG == TX_TIMER_NEED_RESTART)
        {
            rt_timer_control(timer_ptr, RT_TIMER_CTRL_SET_TIME, timer_ptr->tx_timer_internal_re_initialize_ticks);
        }
    }
}
