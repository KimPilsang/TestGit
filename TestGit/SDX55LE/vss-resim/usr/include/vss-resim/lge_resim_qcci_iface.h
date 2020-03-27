#ifndef __LGE_RESIM_QCCI_IFACE_H__
#define __LGE_RESIM_QCCI_IFACE_H__
/*===========================================================================

                          INCLUDE FILES FOR MODULE

===========================================================================*/
#include "qmi_client.h"

/*===========================================================================

                            CONSTANT DEFINITIONS

===========================================================================*/

/*===========================================================================

                                DATA TYPES

===========================================================================*/

/*===========================================================================

                               INTERNAL DATA

===========================================================================*/


/*===========================================================================
  FUNCTION  qcci_qmi_lge_resim_send_cmd
===========================================================================*/


#define MODEM_STATUS_REBOOT_REQUEST  1
#define MODEM_STATUS_OK  0
#define MODEM_STATUS_CONNECTION_FAILED  -1
#define MODEM_STATUS_UNSUPPORTED_COMMAND  -2
#define MODEM_STATUS_VERIFICATION_FAILED  -3
#define MODEM_STATUS_BUFFER_TOO_SHORT  -4
#define MODEM_STATUS_COMMAND_FAILED  -5
#define MODEM_STATUS_GET_TIME_FAILED = -6


qmi_client_error_type
qcci_qmi_lge_resim_send_cmd
(
    unsigned int       msg_id,
    void               *req_c_struct,
    unsigned int       req_c_struct_len,
    void               *resp_c_struct,
    unsigned int       resp_c_struct_len,
    unsigned int       timeout_msecs
);
#endif
