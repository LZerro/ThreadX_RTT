#define TX_SOURCE_CODE

#include "tx_api.h"

UINT  _tx_event_flags_create(TX_EVENT_FLAGS_GROUP *group_ptr, CHAR *name_ptr)
{
    RT_ASSERT(group_ptr);

    rt_even_init((rt_event_t)group_ptr, name_ptr);

    return TX_SUCCESS;
}
