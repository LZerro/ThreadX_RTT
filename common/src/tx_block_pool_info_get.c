#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_block_pool_info_get(TX_BLOCK_POOL *pool_ptr, CHAR **name, ULONG *available_blocks,
                              ULONG *total_blocks, TX_THREAD **first_suspended,
                              ULONG *suspended_count, TX_BLOCK_POOL **next_pool)
{
    RT_ASSERT(pool_ptr && name && available_blocks && total_blocks && first_suspended && suspended_count && next_pool);

    rt_list_t *n;
    rt_mp_t Block_pool_temp_ptr = (rt_mp_t)pool_ptr;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = Block_pool_temp_ptr->parent.name;

    *available_blocks = Block_pool_temp_ptr->block_free_count;

    *first_suspended = Block_pool_temp_ptr->suspend_thread.next;

    for (n = Block_pool_temp_ptr->suspend_thread.next; n != &(Block_pool_temp_ptr->suspend_thread); n = n->next, suspended_count++);

    *next_pool = TX_NULL;

    rt_hw_interrupt_enable( level );
}