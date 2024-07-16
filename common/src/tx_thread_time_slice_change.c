#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_time_slice_change(TX_THREAD *thread_ptr, ULONG new_time_slice, ULONG *old_time_slice)
{
    rt_base_t level;
    level = rt_hw_interrupt_disable();
    if(thread_ptr != RT_NULL)
    {
        old_time_slice = RT_SCHED_PRIV((rt_thread_t)thread).init_tick;
        RT_SCHED_PRIV((rt_thread_t)thread).init_tick = new_time_slice;
        rt_hw_interrupt_enable( level );
    }
    else
    {
        rt_hw_interrupt_enable( level );
    }
    return  TX_SUCCESS;
}
