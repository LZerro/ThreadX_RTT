#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_block_pool_info_get(TX_BLOCK_POOL *pool_ptr, CHAR **name, ULONG *available_blocks,
                              ULONG *total_blocks, TX_THREAD **first_suspended,
                              ULONG *suspended_count, TX_BLOCK_POOL **next_pool)
{
    RT_ASSERT(pool_ptr && name && available_blocks && total_blocks && first_suspended && suspended_count && next_pool);

    struct rt_list_node *n;
    *suspended_count = 0;
    rt_base_t level;
    level = rt_hw_interrupt_disable();

    *name = pool_ptr->parent.name;

    *available_blocks = pool_ptr->block_free_count;

    *first_suspended = pool_ptr->suspend_thread.next;

    for (n = pool_ptr->suspend_thread.next; n != pool_ptr->suspend_thread; n = n->next, suspended_count++);

    *next_pool = TX_NULL;

    rt_hw_interrupt_enable( level );
}