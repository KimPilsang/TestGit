#ifndef LGE_RESIM_SERVICE_H
#define LGE_RESIM_SERVICE_H
/**
  @file lge_resim_service_v02.h
  
  @brief This is the public header file which defines the lge_resim service Data structures.

  This header file defines the types and structures that were defined in 
  lge_resim. It contains the constant values defined, enums, structures,
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
   It was generated on: Mon Aug 26 2019
   From IDL File: lge_resim_service_v02.idl */

/** @defgroup lge_resim_qmi_consts Constant values defined in the IDL */
/** @defgroup lge_resim_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup lge_resim_qmi_enums Enumerated types used in QMI messages */
/** @defgroup lge_resim_qmi_messages Structures sent as QMI messages */
/** @defgroup lge_resim_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup lge_resim_qmi_accessor Accessor for QMI service object */
/** @defgroup lge_resim_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup lge_resim_qmi_version 
    @{ 
  */ 
/** Major Version Number of the IDL used to generate this file */
#define LGE_RESIM_V02_IDL_MAJOR_VERS 0x02
/** Revision Number of the IDL used to generate this file */
#define LGE_RESIM_V02_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define LGE_RESIM_V02_IDL_TOOL_VERS 0x05
/** Maximum Defined Message ID */
#define LGE_RESIM_V02_MAX_MESSAGE_ID 0x060C;
/** 
    @} 
  */


/** @addtogroup lge_resim_qmi_consts 
    @{ 
  */
#define QMI_RESIM_TEST_DATA_MAX_V02 1024
#define QMI_RESIM_INDICATION_MAX_V02 1024
#define QMI_VSS_RESIM_SHARED2_DATA_MAX_V02 256
#define QMI_VSS_RESIM_SHARED2_IND_DATA_MAX_V02 1024
#define QMI_VSS_RESIM_UPBLOB_DATA_MAX_V02 1024
#define QMI_VSS_RESIM_UPBLOB_IND_DATA_MAX_V02 1024
#define QMI_VSS_RESIM_SETINFO_IND_DATA_MAX_V02 1024
#define QMI_VSS_RESIM_VERSION_ID_V02 4
#define QMI_VSS_RESIM_RESET_IND_DATA_MAX_V02 1024
#define QMI_VSS_RESIM_LOCK_STATE_V02 4
#define QMI_VSS_RESIM_SEC_BYE_V02 4
#define QMI_VSS_RESIM_NUM_MMC_MNC_V02 2
#define QMI_VSS_RESIM_SET_MCC_MNC_V02 512
#define QMI_VSS_RESIM_GET_MODEM_IND_DATA_MAX_V02 1024
#define TRF_ENCRYPT_DATA_V02 1024
#define TFSIM_ENCRYPT_DATA_V02 1024
#define QMI_VSS_RESIM_SC_DATA_MAX_V02 1024
#define QMI_VSS_RESIM_SL_FUSG_DATA_MAX_V02 1024
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t test_tlv;
}vss_resim_test_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
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
  char data[QMI_RESIM_TEST_DATA_MAX_V02];
}vss_resim_test_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t data_valid;  /**< Must be set to true if data is being passed */
  char data[QMI_RESIM_INDICATION_MAX_V02];
}vss_resim_test_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t request_id;
}vss_resim_shared2_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  int32_t shared_key_resp;

  /* Mandatory */
  uint8_t resp_data[QMI_VSS_RESIM_SHARED2_DATA_MAX_V02];
}vss_resim_shared2_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t ind_data_valid;  /**< Must be set to true if ind_data is being passed */
  uint8_t ind_data[QMI_VSS_RESIM_SHARED2_IND_DATA_MAX_V02];
}vss_resim_shared2_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t request_id;

  /* Mandatory */
  uint8_t upblob[QMI_VSS_RESIM_UPBLOB_DATA_MAX_V02];
}vss_resim_upblob_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  int32_t simblob_resp;
}vss_resim_upblob_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t ind_data_valid;  /**< Must be set to true if ind_data is being passed */
  uint8_t ind_data[QMI_VSS_RESIM_UPBLOB_IND_DATA_MAX_V02];
}vss_resim_upblob_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t request_id;
}vss_resim_setinfo_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  int32_t state_resp;

  /* Mandatory */
  uint8_t version_id[QMI_VSS_RESIM_VERSION_ID_V02];
}vss_resim_setinfo_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t ind_data_valid;  /**< Must be set to true if ind_data is being passed */
  uint8_t ind_data[QMI_VSS_RESIM_SETINFO_IND_DATA_MAX_V02];
}vss_resim_setinfo_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t request_id;
}vss_resim_reset_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  int32_t reset_resp;
}vss_resim_reset_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t ind_data_valid;  /**< Must be set to true if ind_data is being passed */
  uint8_t ind_data[QMI_VSS_RESIM_RESET_IND_DATA_MAX_V02];
}vss_resim_reset_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t test_tlv;
}vss_resim_connect_callback_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;
}vss_resim_connect_callback_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t request_id;
}vss_resim_get_modem_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  uint8_t unlock_state[QMI_VSS_RESIM_LOCK_STATE_V02];

  /* Mandatory */
  uint8_t left_sec[QMI_VSS_RESIM_SEC_BYE_V02];

  /* Mandatory */
  uint8_t num_mcc_mnc[QMI_VSS_RESIM_NUM_MMC_MNC_V02];

  /* Mandatory */
  uint8_t mcc_mnc[QMI_VSS_RESIM_SET_MCC_MNC_V02];
}vss_resim_get_modem_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t param;

  /* Optional */
  uint8_t ind_data_valid;  /**< Must be set to true if ind_data is being passed */
  uint8_t ind_data[QMI_VSS_RESIM_GET_MODEM_IND_DATA_MAX_V02];
}vss_resim_get_modem_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_rpmb_req[TRF_ENCRYPT_DATA_V02];
}vss_resim_trf_rpmb_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_rpmb_resp[TRF_ENCRYPT_DATA_V02];
}vss_resim_trf_rpmb_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_rpmb_ind[TRF_ENCRYPT_DATA_V02];
}vss_resim_trf_rpmb_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint32_t request_id;

  /* Mandatory */
  uint8_t encrypt[TRF_ENCRYPT_DATA_V02];
}vss_resim_trf_unlock_req_msg_v02_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  int32_t unlock_resp;

  /* Mandatory */
  uint8_t encrypt[TRF_ENCRYPT_DATA_V02];
}vss_resim_trf_unlock_resp_msg_v02_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_match_req[TRF_ENCRYPT_DATA_V02];
}vss_resim_trf_match_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_match_resp[TRF_ENCRYPT_DATA_V02];
}vss_resim_trf_match_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t data_valid;
}vss_resim_trf_match_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_tftamper_req[TFSIM_ENCRYPT_DATA_V02];
}vss_resim_trf_tftamper_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_tftamper_resp[TFSIM_ENCRYPT_DATA_V02];
}vss_resim_trf_tftamper_resp_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t tfsim_tftamper_ind[TFSIM_ENCRYPT_DATA_V02];
}vss_resim_trf_tftamper_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t sc_data[QMI_VSS_RESIM_SC_DATA_MAX_V02];
}vss_resim_secure_channel_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  uint8_t sc_data[QMI_VSS_RESIM_SC_DATA_MAX_V02];
}vss_resim_secure_channel_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  uint8_t sl_fusg_data[QMI_VSS_RESIM_SL_FUSG_DATA_MAX_V02];
}vss_resim_simlock_fusg_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_resim_qmi_messages
    @{
  */
/**  Message;  */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  uint8_t sl_fusg_data[QMI_VSS_RESIM_SL_FUSG_DATA_MAX_V02];
}vss_resim_simlock_fusg_resp_msg_v02;  /* Message */
/**
    @}
  */

/*Service Message Definition*/
/** @addtogroup lge_resim_qmi_msg_ids
    @{
  */
#define QMI_RESIM_TEST_REQ_MSG_V02 0x0600
#define QMI_RESIM_TEST_RESP_MSG_V02 0x0600
#define QMI_RESIM_TEST_IND_MSG_V02 0x0600
#define QMI_VSS_RESIM_CONNECT_CB_REQ_MSG_V02 0x0601
#define QMI_VSS_RESIM_CONNECT_CB_RESP_MSG_V02 0x0601
#define QMI_VSS_RESIM_SHARED2_REQ_MSG_V02 0x0602
#define QMI_VSS_RESIM_SHARED2_RESP_MSG_V02 0x0602
#define QMI_VSS_RESIM_SHARED2_IND_MSG_V02 0x0602
#define QMI_VSS_RESIM_UPBLOB_REQ_MSG_V02 0x0603
#define QMI_VSS_RESIM_UPBLOB_RESP_MSG_V02 0x0603
#define QMI_VSS_RESIM_UPBLOB_IND_MSG_V02 0x0603
#define QMI_VSS_RESIM_SETINFO_REQ_MSG_V02 0x0604
#define QMI_VSS_RESIM_SETINFO_RESP_MSG_V02 0x0604
#define QMI_VSS_RESIM_SETINFO_IND_MSG_V02 0x0604
#define QMI_VSS_RESIM_RESET_REQ_MSG_V02 0x0605
#define QMI_VSS_RESIM_RESET_RESP_MSG_V02 0x0605
#define QMI_VSS_RESIM_RESET_IND_MSG_V02 0x0605
#define QMI_VSS_RESIM_GET_MODEM_REQ_MSG_V02 0x0606
#define QMI_VSS_RESIM_GET_MODEM_RESP_MSG_V02 0x0606
#define QMI_VSS_RESIM_GET_MODEM_IND_MSG_V02 0x0606
#define QMI_VSS_RESIM_TRF_RPMB_REQ_MSG_V02 0x0607
#define QMI_VSS_RESIM_TRF_RPMB_RESP_MSG_V02 0x0607
#define QMI_VSS_RESIM_TRF_RPMB_IND_MSG_V02 0x0607
#define QMI_VSS_RESIM_TRF_UNLOCK_REQ_MSG_V02_V02 0x0608
#define QMI_VSS_RESIM_TRF_UNLOCK_RESP_MSG_V02_V02 0x0608
#define QMI_VSS_RESIM_TRF_MATCH_REQ_MSG_V02 0x0609
#define QMI_VSS_RESIM_TRF_MATCH_RESP_MSG_V02 0x0609
#define QMI_VSS_RESIM_TRF_MATCH_IND_MSG_V02 0x0609
#define QMI_VSS_RESIM_TRF_TFTAMPER_REQ_MSG_V02 0x060A
#define QMI_VSS_RESIM_TRF_TFTAMPER_RESP_MSG_V02 0x060A
#define QMI_VSS_RESIM_TRF_TFTAMPER_IND_MSG_V02 0x060A
#define QMI_VSS_RESIM_SECURE_CHANNEL_REQ_MSG_V02 0x060B
#define QMI_VSS_RESIM_SECURE_CHANNEL_RESP_MSG_V02 0x060B
#define QMI_VSS_RESIM_SIMLOCK_FUSG_REQ_MSG_V02 0x060C
#define QMI_VSS_RESIM_SIMLOCK_FUSG_RESP_MSG_V02 0x060C
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor 
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro lge_resim_get_service_object_v02( ) that takes in no arguments. */
qmi_idl_service_object_type lge_resim_get_service_object_internal_v02
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );
 
/** This macro should be used to get the service object */ 
#define lge_resim_get_service_object_v02( ) \
          lge_resim_get_service_object_internal_v02( \
            LGE_RESIM_V02_IDL_MAJOR_VERS, LGE_RESIM_V02_IDL_MINOR_VERS, \
            LGE_RESIM_V02_IDL_TOOL_VERS )
/** 
    @} 
  */


#ifdef __cplusplus
}
#endif
#endif

