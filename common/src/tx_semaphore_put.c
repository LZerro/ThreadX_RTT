#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_semaphore_put(TX_SEMAPHORE *semaphore_ptr)
{
    RT_ASSERT(semaphore_ptr);

    rt_sem_release((rt_sem_t)semaphore_ptr);

    return TX_SUCCESS;
}
