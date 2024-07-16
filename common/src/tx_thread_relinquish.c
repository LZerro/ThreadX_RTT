#define TX_SOURCE_CODE

#include "tx_api.h"

VOID  _tx_thread_relinquish(VOID)
{
    rt_thread_yield();
}
