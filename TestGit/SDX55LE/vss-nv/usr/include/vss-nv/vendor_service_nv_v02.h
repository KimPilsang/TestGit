#ifndef VS_NV_SERVICE_V02_H
#define VS_NV_SERVICE_V02_H
/**
  @file vendor_service_nv_v02.h

  @brief This is the public header file which defines the vs_nv service Data structures.

  This header file defines the types and structures that were defined in
  vs_nv. It contains the constant values defined, enums, structures,
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
   It was generated on: Thu Sep 11 2014
   From IDL File: vendor_service_nv_v02.idl */

/** @defgroup vs_nv_qmi_consts Constant values defined in the IDL */
/** @defgroup vs_nv_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup vs_nv_qmi_enums Enumerated types used in QMI messages */
/** @defgroup vs_nv_qmi_messages Structures sent as QMI messages */
/** @defgroup vs_nv_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup vs_nv_qmi_accessor Accessor for QMI service object */
/** @defgroup vs_nv_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup vs_nv_qmi_version 
    @{ 
  */ 
/** Major Version Number of the IDL used to generate this file */
#define VS_NV_V02_IDL_MAJOR_VERS 0x02
/** Revision Number of the IDL used to generate this file */
#define VS_NV_V02_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define VS_NV_V02_IDL_TOOL_VERS 0x05
/** Maximum Defined Message ID */
#define VS_NV_V02_MAX_MESSAGE_ID 0x0609;
/** 
    @} 
  */


/** @addtogroup vs_nv_qmi_consts 
    @{ 
  */
#define QMI_VS_NV_ITEM_LEN_V02 200
#define QMI_VS_NV_RAW_LEN_V02 1024
#define QMI_NV_TEST_DATA_MAX_V02 1024
#define QMI_NV_INDICATION_MAX_V02 1024
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t item_num;

  /* Optional */
  uint8_t nv_arr_valid;  /**< Must be set to true if nv_arr is being passed */
  uint8_t nv_arr[QMI_VS_NV_ITEM_LEN_V02];
}vs_nv_read_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Optional */
  uint8_t item_num_valid;  /**< Must be set to true if item_num is being passed */
  uint32_t item_num;

  /* Optional */
  uint8_t nv_arr_valid;  /**< Must be set to true if nv_arr is being passed */
  uint8_t nv_arr[QMI_VS_NV_ITEM_LEN_V02];
}vs_nv_read_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t item_num;

  /* Mandatory */
  uint8_t nv_arr[QMI_VS_NV_ITEM_LEN_V02];
}vs_nv_write_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  uint32_t item_num;
}vs_nv_write_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t item_id;
}vs_nv_read_raw_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  uint32_t item_id;

  /* Mandatory */
  uint32_t nv_arr_len;

  /* Mandatory */
  uint8_t nv_arr[QMI_VS_NV_RAW_LEN_V02];
}vs_nv_read_raw_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t item_id;

  /* Mandatory */
  uint32_t nv_arr_len;

  /* Mandatory */
  uint8_t nv_arr[QMI_VS_NV_RAW_LEN_V02];
}vs_nv_write_raw_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Optional */
  uint8_t item_id_valid;  /**< Must be set to true if item_id is being passed */
  uint32_t item_id;
}vs_nv_write_raw_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t test_tlv;
}vss_nv_test_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
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
  char data[QMI_NV_TEST_DATA_MAX_V02];
}vss_nv_test_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup vs_nv_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t data_valid;  /**< Must be set to true if data is being passed */
  char data[QMI_NV_INDICATION_MAX_V02];
}vss_nv_test_ind_msg_v02;  /* Message */
/**
    @}
  */

/*Service Message Definition*/
/** @addtogroup vs_nv_qmi_msg_ids
    @{
  */
#define QMI_VS_NV_READ_LOCAL_REQ_MSG_V02 0x0600
#define QMI_VS_NV_READ_LOCAL_RESP_MSG_V02 0x0600
#define QMI_VS_NV_WRITE_LOCAL_REQ_MSG_V02 0x0601
#define QMI_VS_NV_WRITE_LOCAL_RESP_MSG_V02 0x0601
#define QMI_VS_NV_READ_RAW_LOCAL_REQ_MSG_V02 0x0602
#define QMI_VS_NV_READ_RAW_LOCAL_RESP_MSG_V02 0x0602
#define QMI_VS_NV_WRITE_RAW_LOCAL_REQ_MSG_V02 0x0603
#define QMI_VS_NV_WRITE_RAW_LOCAL_RESP_MSG_V02 0x0603
#define QMI_VS_NV_READ_REMOTE_REQ_MSG_V02 0x0604
#define QMI_VS_NV_READ_REMOTE_RESP_MSG_V02 0x0604
#define QMI_VS_NV_WRITE_REMOTE_REQ_MSG_V02 0x0605
#define QMI_VS_NV_WRITE_REMOTE_RESP_MSG_V02 0x0605
#define QMI_VS_NV_READ_RAW_REMOTE_REQ_MSG_V02 0x0606
#define QMI_VS_NV_READ_RAW_REMOTE_RESP_MSG_V02 0x0606
#define QMI_VS_NV_WRITE_RAW_REMOTE_REQ_MSG_V02 0x0607
#define QMI_VS_NV_WRITE_RAW_REMOTE_RESP_MSG_V02 0x0607
#define QMI_NV_TEST_REQ_MSG_V02 0x0609
#define QMI_NV_TEST_RESP_MSG_V02 0x0609
#define QMI_NV_TEST_IND_MSG_V02 0x0609
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor 
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro vs_nv_get_service_object_v02( ) that takes in no arguments. */
qmi_idl_service_object_type vs_nv_get_service_object_internal_v02
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );
 
/** This macro should be used to get the service object */ 
#define vs_nv_get_service_object_v02( ) \
          vs_nv_get_service_object_internal_v02( \
            VS_NV_V02_IDL_MAJOR_VERS, VS_NV_V02_IDL_MINOR_VERS, \
            VS_NV_V02_IDL_TOOL_VERS )
/** 
    @} 
  */


#ifdef __cplusplus
}
#endif
#endif

