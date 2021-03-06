#ifndef __LGE_VSS_QCCI_CORE_H__
#define __LGE_VSS_QCCI_CORE_H__
/*===========================================================================

                          INCLUDE FILES FOR MODULE

===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

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
  FUNCTION  qcci_qmi_lge_vss_init
===========================================================================*/
int qcci_qmi_lge_vss_init(void);

#endif
