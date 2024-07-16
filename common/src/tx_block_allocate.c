#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_block_allocate(TX_BLOCK_POOL *pool_ptr, VOID **block_ptr, ULONG wait_option)
{
    RT_ASSERT(pool_ptr);
    RT_ASSERT(block_ptr);

    block_ptr = TX_INDIRECT_VOID_TO_UCHAR_POINTER_CONVERT(block_ptr);
    if(*block_ptr = rt_mp_alloc((rt_mp_t)pool_ptr, wait_option) == RT_EOK)
    {
        return TX_SUCCESS;
    }
    return TX_NO_MEMORY;
}
