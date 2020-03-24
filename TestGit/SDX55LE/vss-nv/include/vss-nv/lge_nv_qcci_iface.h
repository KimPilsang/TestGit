#ifndef __LGE_NV_QCCI_IFACE_H__
#define __LGE_NV_QCCI_IFACE_H__
/*---------------------------------------------------------------------------
   LGE_VSS_QCCI_IFACE.H
---------------------------------------------------------------------------*/
/*!
  @file
    lge_nv_qcci_iface.h

  @brief
    This file contains the APIs of interface function for the Vendor Specific NV service.

*/
/*--------------------------------------------------------------------------
  Copyright (c) 2012 LGE MC
  All Rights Reserved. LGE Proprietary and Confidential.
---------------------------------------------------------------------------*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

$Header: //android/vendor/lge/vss/lge_vss_qcci_iface/src/lge_nv_qcci_iface.h#1 $

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

/*===========================================================================

                               INTERNAL DATA

===========================================================================*/


/*===========================================================================
  FUNCTION  qcci_qmi_lge_nv_send_cmd
===========================================================================*/
qmi_client_error_type
qcci_qmi_lge_nv_send_cmd
(
    unsigned int       msg_id,
    void               *req_c_struct,
    unsigned int       req_c_struct_len,
    void               *resp_c_struct,
    unsigned int       resp_c_struct_len,
    unsigned int       timeout_msecs
);

qmi_client_error_type
qcci_qmi_lge_nv_send_cmd_async
(
    unsigned int                    msg_id,
    void                            *req_c_struct,
    unsigned int                    req_c_struct_len,
    void                            *resp_c_struct,
    unsigned int                    resp_c_struct_len,
    qmi_client_recv_msg_async_cb    resp_cb,
    void                            *resp_cb_data,
    qmi_txn_handle                  *txn_handle

);
#endif
