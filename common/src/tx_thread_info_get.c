#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_info_get(TX_THREAD *thread_ptr, CHAR **name, UINT *state, ULONG *run_count,
                          UINT *priority, UINT *preemption_threshold, ULONG *time_slice,
                          TX_THREAD **next_thread, TX_THREAD **next_suspended_thread)
{
    rt_base_t level;
    rt_thread_t Thread_temp_ptr = (rt_thread_t)thread_ptr;
    level = rt_hw_interrupt_disable();

    if(name != TX_NULL)
    {
        *name = Thread_temp_ptr->parent.name;
    }
    if(state != TX_NULL)
    {
        *state = (UINT)RT_SCHED_CTX(Thread_temp_ptr).stat;
    }
    if(run_count != TX_NULL)
    {
#ifdef RT_USING_CPU_USAGE
        rt_uint64_t Thread_Used_Tick = Thread_temp_ptr.duration_tick;
        *run_count = (ULONG)(Thread_Used_Tick / (rt_uint64_t)(RT_SCHED_CTX(Thread_temp_ptr).init_tick));
#else
        *run_count = 0;
#endif //RT_USING_CPU_USAGE
    }
    if(priority != TX_NULL)
    {
        *priority = (UINT)RT_SCHED_CTX(Thread_temp_ptr).current_priority;
    }
    if(preemption_threshold != TX_NULL)
    {
        *preemption_threshold = 0;
    }
    if(time_slice!=TX_NULL)
    {
        *time_slice = (ULONG)RT_SCHED_CTX(Thread_temp_ptr).init_tick;
    }
    if(next_thread != TX_NULL)
    {
        rt_ubase_t highest_ready_priority;
        rt_thread_t to_thread;
        to_thread = _scheduler_get_highest_priority_thread(&highest_ready_priority);
        *next_thread = (TX_THREAD *)to_thread;
    }

    rt_hw_interrupt_enable(level);
}