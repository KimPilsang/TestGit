#ifndef __LGE_GNSS_QCCI_IFACE_H__
#define __LGE_GNSS_QCCI_IFACE_H__
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

//#include <hardware/gps_lge.h>

/*===========================================================================

                            CONSTANT DEFINITIONS

===========================================================================*/




/*===========================================================================

                                DATA TYPES

===========================================================================*/
#define QCRIL_NOTUSED( var ) ((void)(var))

#ifdef __cplusplus
    extern "C" {
#endif

typedef qmi_client_ind_cb (* gnss_ind_cb)
(
    unsigned long                  msg_id,
    unsigned char                  *ind_buf,
    int                            ind_buf_len
);

//[LGE_GNSS][S] LGP_GNSS_Q_0015, LGP_GNSS_ADD_VSS_STATE_CALLBACK, sangeun88.kim, 2019-08-09
typedef void (* vss_state_cb)
(
    int                            connected
);
//[LGE_GNSS][E]

/*===========================================================================

                               INTERNAL DATA

===========================================================================*/


/*===========================================================================

                               FUNCTIONS

===========================================================================*/

int vss_gnss_init(gnss_ind_cb ind_cb, vss_state_cb state_cb_fp); //[LGE_GNSS] LGP_GNSS_Q_0015, LGP_GNSS_ADD_VSS_STATE_CALLBACK, sangeun88.kim, 2019-08-09


qmi_client_error_type
qcci_qmi_lge_gnss_send_cmd
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
