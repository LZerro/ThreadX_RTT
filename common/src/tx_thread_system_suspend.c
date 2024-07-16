#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_thread.h"

VOID  _tx_thread_system_suspend(TX_THREAD *thread_ptr)
{
    RT_ASSERT(thread_ptr);
    rt_thread_suspend((rt_thread_t)thread_ptr);
    rt_schedule();
}
