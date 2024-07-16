#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_block_pool_delete(TX_BLOCK_POOL *pool_ptr)
{
    RT_ASSERT(pool_ptr);

    rt_mp_detach((rt_mp_t)pool_ptr);

    return TX_SUCCESS;
}
