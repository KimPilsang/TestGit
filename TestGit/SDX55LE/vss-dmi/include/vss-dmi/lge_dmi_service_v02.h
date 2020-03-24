#ifndef LGE_DMI_SERVICE_V02_H
#define LGE_DMI_SERVICE_V02_H
/**
  @file lge_dmi_service_v02.h
  
  @brief This is the public header file which defines the lge_dmi service Data structures.

  This header file defines the types and structures that were defined in 
  lge_dmi. It contains the constant values defined, enums, structures,
  messages, and service message IDs (in that order) Structures that were 
  defined in the IDL as messages contain mandatory elements, optional 
  elements, a combination of mandatory and optional elements (mandatory 
  always come before optionals in the structure), or nothing (null message)
   
  An optional element in a message is preceded by a uint8_t value that must be
  set to true if the element is going to be included. When decoding a received
  message, the uint8_t values will be set to true or false by the decode
  routine, and should be checked before accessing the values that they
  correspond to. 
   
  Variable sized arrays are defined as static sized arrays with an unsigned
  integer (32 bit) preceding it that must be set to the number of elements
  in the array that are valid. For Example:
   
  uint32_t test_opaque_len;
  uint8_t test_opaque[16];
   
  If only 4 elements are added to test_opaque[] then test_opaque_len must be
  set to 4 before sending the message.  When decoding, the _len value is set 
  by the decode routine and should be checked so that the correct number of 
  elements in the array will be accessed. 

*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  

  
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====* 
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY 
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 5.1 
   It was generated on: Thu Apr  3 2014
   From IDL File: lge_dmi_service_v02.idl */

/** @defgroup lge_dmi_qmi_consts Constant values defined in the IDL */
/** @defgroup lge_dmi_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup lge_dmi_qmi_enums Enumerated types used in QMI messages */
/** @defgroup lge_dmi_qmi_messages Structures sent as QMI messages */
/** @defgroup lge_dmi_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup lge_dmi_qmi_accessor Accessor for QMI service object */
/** @defgroup lge_dmi_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup lge_dmi_qmi_version 
    @{ 
  */ 
/** Major Version Number of the IDL used to generate this file */
#define LGE_DMI_V02_IDL_MAJOR_VERS 0x02
/** Revision Number of the IDL used to generate this file */
#define LGE_DMI_V02_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define LGE_DMI_V02_IDL_TOOL_VERS 0x05
/** Maximum Defined Message ID */
#define LGE_DMI_V02_MAX_MESSAGE_ID 0x0601;
/** 
    @} 
  */


/** @addtogroup lge_dmi_qmi_consts 
    @{ 
  */
#define LGE_DMI_DATA_MAX_SIZE_V02 255
#define QMI_LGE_DMI_INFO_MAX_V02 1024
#define QMI_DMI_TEST_DATA_MAX_V02 1024
#define QMI_DMI_INDICATION_MAX_V02 1024
/**
    @}
  */

/** @addtogroup lge_dmi_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t data_len;

  uint8_t data[LGE_DMI_DATA_MAX_SIZE_V02];
}lge_dmi_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup lge_dmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t request_id;

  /* Optional */
  uint8_t value_valid;  /**< Must be set to true if value is being passed */
  lge_dmi_info_type_v02 value;
}lge_dmi_info_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_dmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Optional */
  uint8_t value_valid;  /**< Must be set to true if value is being passed */
  lge_dmi_info_type_v02 value;
}lge_dmi_info_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_dmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t test_tlv;
}vss_dmi_test_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_dmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  int32_t test_rsp;

  /* Optional */
  uint8_t data_valid;  /**< Must be set to true if data is being passed */
  char data[QMI_DMI_TEST_DATA_MAX_V02];
}vss_dmi_test_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_dmi_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t data_valid;  /**< Must be set to true if data is being passed */
  char data[QMI_DMI_INDICATION_MAX_V02];
}vss_dmi_test_ind_msg_v02;  /* Message */
/**
    @}
  */

/*Service Message Definition*/
/** @addtogroup lge_dmi_qmi_msg_ids
    @{
  */
#define QMI_LGE_DMI_INFO_REQ_MSG_V02 0x0600
#define QMI_LGE_DMI_INFO_RESP_MSG_V02 0x0600
#define QMI_LGE_DMI_TEST_REQ_MSG_V02 0x0601
#define QMI_LGE_DMI_TEST_RESP_MSG_V02 0x0601
#define QMI_LGE_DMI_TEST_IND_MSG_V02 0x0601
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor 
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro lge_dmi_get_service_object_v02( ) that takes in no arguments. */
qmi_idl_service_object_type lge_dmi_get_service_object_internal_v02
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );
 
/** This macro should be used to get the service object */ 
#define lge_dmi_get_service_object_v02( ) \
          lge_dmi_get_service_object_internal_v02( \
            LGE_DMI_V02_IDL_MAJOR_VERS, LGE_DMI_V02_IDL_MINOR_VERS, \
            LGE_DMI_V02_IDL_TOOL_VERS )
/** 
    @} 
  */


#ifdef __cplusplus
}
#endif
#endif

