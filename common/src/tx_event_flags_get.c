#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_event_flags_get(TX_EVENT_FLAGS_GROUP *group_ptr, ULONG requested_flags,
                          UINT get_option, ULONG *actual_flags_ptr, ULONG wait_option)
{
    RT_ASSERT(group_ptr);

    if(rt_event_recv((rt_event_t)group_ptr, requested_flags, get_option, wait_option, actual_flags_ptr) == RT_EOK)
    {
        return TX_SUCCESS;
    }
    return TX_NO_EVENTS;

}
