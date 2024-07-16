#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_thread.h"

UINT  _tx_thread_suspend(TX_THREAD *thread_ptr)
{
    TX_THREAD *Now_Thread;

    TX_THREAD_GET_CURRENT(Now_Thread)

    if(thread_ptr != Now_Thread)
    {
        return TX_SUSPEND_ERROR;
    }
    else
    {
        _tx_thread_system_suspend(thread_ptr);
        return TX_SUCCESS;
    }
}
