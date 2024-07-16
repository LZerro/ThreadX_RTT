#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_block_release(VOID *block_ptr)
{
    RT_ASSERT(block_ptr);

    rt_mp_free((rt_uint8_t *)block_ptr);

    return TX_SUCCESS;
}
