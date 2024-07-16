#define TX_SOURCE_CODE

#include "tx_api.h"

ULONG  _tx_time_get(VOID)
{
    return rt_tick_get();
}
