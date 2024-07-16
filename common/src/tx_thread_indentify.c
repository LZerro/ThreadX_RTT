#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_thread.h"

TX_THREAD  *_tx_thread_identify(VOID)
{
    TX_THREAD *thread_ptr;
    TX_THREAD_GET_CURRENT(thread_ptr)
    return thread_ptr;
}
