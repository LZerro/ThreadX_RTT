#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_thread_priority_change(TX_THREAD *thread_ptr, UINT new_priority, UINT *old_priority)
{
        *old_priority = (UINT)RT_SCHED_CTX(thread_ptr).current_priority;
        rt_err_t Res = rt_thread_control((rt_thread_t)thread_ptr, RT_THREAD_CTRL_CHANGE_PRIORITY, new_priority);
        if(Res == RT_EOK)
        {
            return TX_SUCCESS;
        }
}
