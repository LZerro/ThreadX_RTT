#define TX_SOURCE_CODE

#include "tx_api.h"
#include "tx_event_flags.h"

UINT  _tx_event_flags_create(TX_EVENT_FLAGS_GROUP *group_ptr, CHAR *name_ptr)
{
    RT_ASSERT(group_ptr);

    rt_event_init((rt_event_t)group_ptr, name_ptr, RT_IPC_FLAG_PRIO);

    group_ptr->tx_event_flags_group_id = TX_EVENT_FLAGS_ID;

    return TX_SUCCESS;
}
