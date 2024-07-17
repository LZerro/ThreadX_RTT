#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_semaphore_get(TX_SEMAPHORE *semaphore_ptr, ULONG wait_option)
{
    RT_ASSERT(semaphore_ptr);

    if(rt_sem_take((rt_sem_t)semaphore_ptr, wait_option) == RT_EOK)
    {
        return TX_SUCCESS;
    }

    semaphore_ptr -> tx_semaphore_count--;

    return TX_NO_INSTANCE;
}