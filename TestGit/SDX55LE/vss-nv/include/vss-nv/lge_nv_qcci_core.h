#ifndef __LGE_NV_QCCI_CORE_H__
#define __LGE_NV_QCCI_CORE_H__
/*---------------------------------------------------------------------------
   LGE_NV_QCCI_CORE.H
---------------------------------------------------------------------------*/
/*!
  @file
    lge_nv_qcci_core.h

  @brief
    This file contains the APIs of core function for the vss service.

*/
/*--------------------------------------------------------------------------
  Copyright (c) 2012 LGE MC
  All Rights Reserved. LGE Proprietary and Confidential.
---------------------------------------------------------------------------*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

$Header: //android/vendor/lge/vss/lge_vss_qcci_core/src/lge_nv_qcci_core.h#1 $

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
#define QCRIL_NOTUSED( var ) ((void)(var))
/*===========================================================================

                               INTERNAL DATA

===========================================================================*/


/*===========================================================================
  FUNCTION  qcci_qmi_lge_vs_nv_init
===========================================================================*/
int qcci_qmi_lge_vs_nv_init(void);
#endif