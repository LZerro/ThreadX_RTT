#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_mutex_create(TX_MUTEX *mutex_ptr, CHAR *name_ptr, UINT inherit)
{
    if(mutex_ptr != TX_NULL)
    {
        rt_mutex_init((rt_mutex_t)mutex_ptr, name_ptr, RT_IPC_FLAG_PRIO);
    }
    return TX_SUCCESS;
}
