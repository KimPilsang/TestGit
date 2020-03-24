#ifndef LGE_GNSS_SERVICE_02_H
#define LGE_GNSS_SERVICE_02_H
/**
  @file lge_gnss_service_v02.h
  
  @brief This is the public header file which defines the lge_gnss service Data structures.

  This header file defines the types and structures that were defined in 
  lge_gnss. It contains the constant values defined, enums, structures,
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
   It was generated on: Tue Mar 29 2016
   From IDL File: lge_gnss_service_v02.idl */

/** @defgroup lge_gnss_qmi_consts Constant values defined in the IDL */
/** @defgroup lge_gnss_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup lge_gnss_qmi_enums Enumerated types used in QMI messages */
/** @defgroup lge_gnss_qmi_messages Structures sent as QMI messages */
/** @defgroup lge_gnss_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup lge_gnss_qmi_accessor Accessor for QMI service object */
/** @defgroup lge_gnss_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup lge_gnss_qmi_version 
    @{ 
  */ 
/** Major Version Number of the IDL used to generate this file */
#define LGE_GNSS_V02_IDL_MAJOR_VERS 0x02
/** Revision Number of the IDL used to generate this file */
#define LGE_GNSS_V02_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define LGE_GNSS_V02_IDL_TOOL_VERS 0x05
/** Maximum Defined Message ID */
#define LGE_GNSS_V02_MAX_MESSAGE_ID 0x0706;
/** 
    @} 
  */


/** @addtogroup lge_gnss_qmi_consts 
    @{ 
  */
#define QMI_GNSS_MAX_SUPL_CERT_LENGTH_V02 2000

/**   Maximum length of the GNSS LGE COMMAND message.  */
#define QMI_GNSS_MAX_MESSAGE_LENGTH_V02 2000
#define QMI_GNSS_MAX_NMEA_LENGTH_V02 200
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Request Message; Test command */
typedef struct {

  /* Mandatory */
  char msg[4];
}lge_gnss_test_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Response Message; Test command */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;
}lge_gnss_test_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Indication Message; Test command */
typedef struct {

  /* Mandatory */
  uint32_t status;
}lge_gnss_test_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Request Message; connection command */
typedef struct {

  /* Mandatory */
  uint32_t status;
}lge_gnss_connect_callback_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Response Message; connection command */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;
}lge_gnss_connect_callback_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Request Message; Certification indication command */
typedef struct {

  /* Mandatory */
  uint8_t suplCertId;

  /* Mandatory */
  uint32_t suplCertData_len;

  /* Mandatory */
  uint8_t suplCertData[QMI_GNSS_MAX_SUPL_CERT_LENGTH_V02];
}lge_gnss_cert_inject_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Response Message; Certification indication command */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;
}lge_gnss_cert_inject_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Indication Message; Certification indication command */
typedef struct {

  /* Mandatory */
  uint32_t status;
}lge_gnss_cert_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Request Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  uint32_t command_id;

  /* Mandatory */
  uint32_t command_param;

  /* Mandatory */
  uint8_t msg[QMI_GNSS_MAX_MESSAGE_LENGTH_V02];
}lge_gnss_command_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Response Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;
}lge_gnss_command_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** Indication Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  uint32_t status;
}lge_gnss_command_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/**  Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  uint32_t command_param;
}lge_gnss_vzqfield_flag_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/**  Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;
}lge_gnss_vzqfield_flag_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/**  Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  uint8_t msg_nmea_data[QMI_GNSS_MAX_NMEA_LENGTH_V02];

  /* Mandatory */
  uint32_t length;
}lge_gnss_vzqfield_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/**  Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  uint32_t command_id;
}lge_gnss_pde_addr_port_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/**  Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  uint32_t pde_server;

  /* Mandatory */
  uint32_t pde_port;
}lge_gnss_pde_addr_port_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/** req,resp,Ind Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  uint32_t cmd;

  /* Mandatory */
  uint32_t param;

  /* Mandatory */
  char msg[QMI_GNSS_MAX_MESSAGE_LENGTH_V02];
}lge_gnss_general_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/**  Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  qmi_response_type_v01 resp;

  /* Mandatory */
  uint32_t return_value;

  /* Mandatory */
  char msg[QMI_GNSS_MAX_MESSAGE_LENGTH_V02];
}lge_gnss_general_rsp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup lge_gnss_qmi_messages
    @{
  */
/**  Message; Lge Gnss command */
typedef struct {

  /* Mandatory */
  uint32_t cmd;

  /* Mandatory */
  uint32_t param;

  /* Mandatory */
  char msg[QMI_GNSS_MAX_MESSAGE_LENGTH_V02];
}lge_gnss_general_ind_msg_v02;  /* Message */
/**
    @}
  */

/*Service Message Definition*/
/** @addtogroup lge_gnss_qmi_msg_ids
    @{
  */
#define QMI_LGE_GNSS_TEST_REQ_MSG_V02 0x0700
#define QMI_LGE_GNSS_TEST_RESP_MSG_V02 0x0700
#define QMI_LGE_GNSS_TEST_IND_MSG_V02 0x0700
#define QMI_LGE_GNSS_CONNECT_CB_REQ_MSG_V02 0x0701
#define QMI_LGE_GNSS_CONNECT_CB_RESP_MSG_V02 0x0701
#define QMI_LGE_GNSS_CERT_INJECT_REQ_MSG_V02 0x0702
#define QMI_LGE_GNSS_CERT_INJECT_RESP_MSG_V02 0x0702
#define QMI_LGE_GNSS_CERT_IND_MSG_V02 0x0702
#define QMI_LGE_GNSS_COMMAND_REQ_MSG_V02 0x0703
#define QMI_LGE_GNSS_COMMAND_RESP_MSG_V02 0x0703
#define QMI_LGE_GNSS_COMMAND_IND_MSG_V02 0x0703
#define QMI_LGE_GNSS_VZWFIELD_FLAG_REQ_MSG_V02 0x0704
#define QMI_LGE_GNSS_VZWFIELD_FLAG_RESP_MSG_V02 0x0704
#define QMI_LGE_GNSS_VZWFIELD_IND_MSG_V02 0x0704
#define QMI_LGE_GNSS_PDE_ADDR_PORT_REQ_MSG_V02 0x0705
#define QMI_LGE_GNSS_PDE_ADDR_PORT_RESP_MSG_V02 0x0705
#define QMI_LGE_GNSS_GENERAL_REQ_MSG_V02 0x0706
#define QMI_LGE_GNSS_GENERAL_RSP_MSG_V02 0x0706
#define QMI_LGE_GNSS_GENERAL_IND_MSG_V02 0x0706
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor 
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro lge_gnss_get_service_object_v02( ) that takes in no arguments. */
qmi_idl_service_object_type lge_gnss_get_service_object_internal_v02
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );
 
/** This macro should be used to get the service object */ 
#define lge_gnss_get_service_object_v02( ) \
          lge_gnss_get_service_object_internal_v02( \
            LGE_GNSS_V02_IDL_MAJOR_VERS, LGE_GNSS_V02_IDL_MINOR_VERS, \
            LGE_GNSS_V02_IDL_TOOL_VERS )
/** 
    @} 
  */


#ifdef __cplusplus
}
#endif
#endif

