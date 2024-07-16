#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_thread.h"

VOID  _tx_thread_system_resume(TX_THREAD *thread_ptr)
{
    rt_bool_t need_schedule = RT_FALSE;
    rt_base_t level;

    RT_ASSERT(thread_ptr);

    if( thread_ptr != NULL && thread_ptr != rt_thread_self() )
    {
        level = rt_hw_interrupt_disable();
        /* A task with higher priority than the current running task is ready */
        if ( rt_thread_resume( thread_ptr ) == RT_EOK && thread_ptr->current_priority <= rt_thread_self()->current_priority )
        {
            need_schedule = RT_TRUE;
        }
        rt_hw_interrupt_enable( level );
    }
    if (need_schedule == RT_TRUE)
    {
        rt_schedule();
    }
}
