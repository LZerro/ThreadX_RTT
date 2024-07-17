#define TX_SOURCE_CODE

/* Include necessary system files.  */

#include "tx_api.h"

/* Define any port-specific scheduling data structures.  */

VOID  _tx_initialize_kernel_enter(VOID)
{
    /* Call the application provided initialization function.  Pass the
       first available memory address to it.  */
    tx_application_define(TX_NULL);

}

