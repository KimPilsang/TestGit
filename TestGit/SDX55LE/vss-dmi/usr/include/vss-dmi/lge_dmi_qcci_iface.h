#ifndef __LGE_DMI_QCCI_IFACE_H__
#define __LGE_DMI_QCCI_IFACE_H__
/*---------------------------------------------------------------------------
   LGE_VSS_QCCI_IFACE.H
---------------------------------------------------------------------------*/
/*!
  @file
    lge_vss_qcci_iface.h

  @brief
    This file contains the APIs of interface function for the vss service.

*/
/*--------------------------------------------------------------------------
  Copyright (c) 2012 LGE MC
  All Rights Reserved. LGE Proprietary and Confidential.
---------------------------------------------------------------------------*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

$Header: //android/vendor/lge/vss/lge_vss_qcci_iface/src/lge_vss_qcci_iface.h#1 $

when           who             what, where, why
--------    ---             ---------------------------------------------
01/11/13    changhwan.lee    Initial Revision.
===========================================================================*/
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
#ifdef __cplusplus
    extern "C" {
#endif

/*===========================================================================

                               INTERNAL DATA

===========================================================================*/


/*===========================================================================
  FUNCTION  qcci_qmi_lge_dmi_send_cmd
===========================================================================*/
qmi_client_error_type
qcci_qmi_lge_dmi_send_cmd
(
    unsigned int       msg_id,
    void               *req_c_struct,
    unsigned int       req_c_struct_len,
    void               *resp_c_struct,
    unsigned int       resp_c_struct_len,
    unsigned int       timeout_msecs
);

#ifdef __cplusplus
}
#endif

#endif
