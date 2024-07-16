#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_event_flags_set(TX_EVENT_FLAGS_GROUP *group_ptr, ULONG flags_to_set, UINT set_option)
{
    RT_ASSERT(group_ptr);

    if(set_option != TX_AND)
    {
        rt_event_send((rt_event_t)group_ptr, flags_to_set);
    }

    return TX_SUCCESS;

}