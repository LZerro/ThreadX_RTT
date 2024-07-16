#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_mutex_get(TX_MUTEX *mutex_ptr, ULONG wait_option)
{
    RT_ASSERT(mutex_ptr);

    if(rt_mutex_take((rt_mutex_t)mutex_ptr, wait_option) == RT_EOK)
    {
        return TX_SUCCESS;
    }

    return TX_NOT_AVAILABLE;
}
