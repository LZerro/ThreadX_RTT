#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_semaphore.h"

UINT  _tx_semaphore_create(TX_SEMAPHORE *semaphore_ptr, CHAR *name_ptr, ULONG initial_count)
{
    RT_ASSERT(semaphore_ptr);

    rt_sem_init((rt_sem_t)semaphore_ptr, name_ptr, initial_count, RT_IPC_FLAG_PRIO);

    semaphore_ptr->tx_semaphore_id = TX_SEMAPHORE_ID;

    semaphore_ptr->tx_semaphore_count = initial_count;

    return TX_SUCCESS;
}
