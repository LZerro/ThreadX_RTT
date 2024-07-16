#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_thread.h"

UINT  _tx_thread_wait_abort(TX_THREAD  *thread_ptr)
{
    _tx_thread_system_resume(thread_ptr);
    return  TX_SUCCESS;
}

