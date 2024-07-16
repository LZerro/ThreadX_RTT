#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_semaphore_ceiling_put(TX_SEMAPHORE *semaphore_ptr, ULONG ceiling)
{
    RT_ASSERT(semaphore_ptr);

    rt_uint16_t sem_current_vallue = 0;
    rt_base_t level;
    UINT status;
    level = rt_hw_interrupt_disable();

    sem_current_vallue = (ULONG)((rt_sem_t)semaphore_ptr)->vlaue;
    if(sem_current_vallue < ceiling)
    {
        rt_sem_release((rt_sem_t)semaphore_ptr);
        rt_hw_interrupt_enable( level );

        status = TX_SUCCESS;
    }
    else
    {
        status = TX_CEILING_EXCEEDED;
        rt_hw_interrupt_enable( level );
    }

    return status;
}