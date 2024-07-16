#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_timer.h"

UINT  _tx_timer_info_get(TX_TIMER *timer_ptr, CHAR **name, UINT *active, ULONG *remaining_ticks,
                         ULONG *reschedule_ticks, TX_TIMER **next_timer)
{
    RT_ASSERT(timer_ptr);

    rt_tick_t current_tick;
    rt_tick_t NowTick_to_max;
    rt_base_t level;

    level = rt_hw_interrupt_disable();

    if(name != TX_NULL)
    {
        *name = ((rt_timer_t)timer_ptr)->parent.name;
    }

    if(active != TX_NULL)
    {
        if(((rt_timer_t)timer_ptr)->parent.flag & RT_TIMER_FLAG_ACTIVATED)
        {
            *active = TX_TRUE;
        }
        else
        {
            *active = TX_FALSE;
        }

    }

    if(remaining_ticks != TX_NULL && active != TX_NULL && *active == TX_TRUE)
    {
        current_tick = rt_tick_get();
        if(current_tick < ((rt_timer_t)timer_ptr)->timeout_tick)
        {
            *remaining_ticks = ((rt_timer_t)timer_ptr)->timeout_tick - current_tick;
        }
        else
        {
            NowTick_to_max = RT_TICK_MAX - current_tick;
            *remaining_ticks = ((rt_timer_t)timer_ptr)->timeout_tick + NowTick_to_max;
        }
    }

    if(reschedule_ticks != TX_NULL)
    {
        *reschedule_ticks = ((rt_timer_t)timer_ptr)->init_tick;
    }

    if(next_timer != TX_NULL)
    {
        *next_timer = TX_NULL;
    }

    rt_hw_interrupt_enable(level);

    return TX_SUCCESS;
}