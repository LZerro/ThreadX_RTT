#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_mutex_put(TX_MUTEX *mutex_ptr)
{
    RT_ASSERT(mutex_ptr);

    if(rt_mutex_release((rt_mutex_t)mutex_ptr) == RT_EOK)
    {
        return TX_SUCCESS;
    }

    return TX_NOT_DONE;
}
