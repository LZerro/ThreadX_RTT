#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_timer.h"

UINT  _tx_timer_delete(TX_TIMER *timer_ptr)
{
    rt_detach((rt_timer_t)timer_ptr);
    return TX_SUCCESS;
}
