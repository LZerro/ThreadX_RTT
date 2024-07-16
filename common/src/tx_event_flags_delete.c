#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_event_flags_delete(TX_EVENT_FLAGS_GROUP *group_ptr)
{
    RT_ASSERT(group_ptr);

    rt_event_detach(group_ptr);

    return TX_SUCCESS;
}
