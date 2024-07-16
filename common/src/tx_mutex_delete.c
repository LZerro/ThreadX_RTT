#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_mutex_delete(TX_MUTEX *mutex_ptr)
{
    if(mutex_ptr != TX_NULL)
    {
        rt_mutex_detach((rt_mutex_t)mutex_ptr);
    }
    return TX_SUCCESS;
}