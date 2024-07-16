#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_block_pool_create(TX_BLOCK_POOL *pool_ptr, CHAR *name_ptr, ULONG block_size,
                            VOID *pool_start, ULONG pool_size)
{
    RT_ASSERT(pool_ptr);

    if(rt_mp_init((rt_mp_t)pool_ptr, name_ptr, pool_start, pool_size, block_size) == RT_EOK)
    {
        return  TX_SUCCESS;
    }
    return  TX_SIZE_ERROR;

}
