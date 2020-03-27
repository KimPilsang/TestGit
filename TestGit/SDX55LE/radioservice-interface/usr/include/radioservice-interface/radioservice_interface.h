#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "oz_common.h"

#define OZ_RADIOSERVICE_NAS_NETWORK_DESCRIPTION_MAX_V01 255
#define OZ_RADIOSERVICE_NAS_3GPP_NETWORK_INFO_LIST_MAX_V01 40

typedef void (*onUnsolResponseRadio)(int response, const void* data);

typedef enum {
  OZ_RADIOSERVICE_REG_NONE,
  OZ_RADIOSERVICE_REG_HOME,
  OZ_RADIOSERVICE_REG_SEARCHING,
  OZ_RADIOSERVICE_REG_DENIED,
  OZ_RADIOSERVICE_REG_UNKNOWN,
  OZ_RADIOSERVICE_REG_ROAMING
} oz_radioservice_registration_state;

typedef enum {
  OZ_RADIOSERVICE_NO_SVC = 0x00,
  OZ_RADIOSERVICE_CDMA_1X = 0x01,
  OZ_RADIOSERVICE_CDMA_1XEVDO = 0x02,
  OZ_RADIOSERVICE_AMPS = 0x03,
  OZ_RADIOSERVICE_GSM = 0x04,
  OZ_RADIOSERVICE_UMTS = 0x05,
  OZ_RADIOSERVICE_WLAN = 0x06,
  OZ_RADIOSERVICE_GPS = 0x07,
  OZ_RADIOSERVICE_LTE = 0x08,
  OZ_RADIOSERVICE_TDSCDMA = 0x09,
  OZ_RADIOSERVICE_NR5G = 0x0C
} oz_radioservice_radiotechnology_type;

typedef enum {
  OZ_RADIOSERVICE_CIOT_SYS_MODE_NO_SRV,
  OZ_RADIOSERVICE_CIOT_SYS_MODE_LTE_WB,
  OZ_RADIOSERVICE_CIOT_SYS_MODE_LTE_M1,
  OZ_RADIOSERVICE_CIOT_SYS_MODE_LTE_NB1,
} oz_radioservice_ciot_ciot_lte_mode;

typedef enum {
  OZ_RADIOSERVICE_OP_MODE_ONLINE,
  OZ_RADIOSERVICE_OP_MODE_LOW_POWER,
  OZ_RADIOSERVICE_OP_MODE_FACTORY_TEST_MODE,
  OZ_RADIOSERVICE_OP_MODE_OFFLINE,
  OZ_RADIOSERVICE_OP_MODE_RESETTING,
  OZ_RADIOSERVICE_OP_MODE_SHUTTING_DOWN,
  OZ_RADIOSERVICE_OP_MODE_PERSISTENT_LOW_POWER,
  OZ_RADIOSERVICE_OP_MODE_MODE_ONLY_LOW_POWER,
  OZ_RADIOSERVICE_OP_MODE_NET_TEST_GW
} oz_radioservice_operating_mode;

typedef enum {
  OZ_RADIOSERVICE_NET_SEL_PREF_AUTOMATIC_V01, 
  OZ_RADIOSERVICE_NET_SEL_PREF_MANUAL_V01 
} oz_radioservice_network_selection;

typedef enum {
  OZ_RADIOSERVICE_MODE_NONE,
  OZ_RADIOSERVICE_MODE_LTE_ONLY,
  OZ_RADIOSERVICE_MODE_NR5G_ONLY,
  OZ_RADIOSERVICE_MODE_LTE_NR5G
} oz_radioservice_network_mode_type;

typedef enum {
  OZ_RADIOSERVICE_NRCDRX_DISABLE,
  OZ_RADIOSERVICE_NRCDRX_ENABLE
} oz_radioservice_nrcdrx_type;


typedef struct {
  int rat;
  int category;
} oz_radioservice_rat_info;

typedef struct {
  int rssi;
  int rsrq;
  int rsrp;
  int snr;
  /* SNR level as a scaled integer in units of 0.1 dB; 
     e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246. */
} oz_radioservice_lte_signal_strength;

typedef struct
{
    char mcc[4];
    char mnc[4];
    int rat;
    char network_description[OZ_RADIOSERVICE_NAS_NETWORK_DESCRIPTION_MAX_V01 + 1];
    int forbidden;
    int mnc_includes_pcs_digit_valid;	
    int mnc_includes_pcs_digit;
} oz_radioservice_network_info;

typedef struct
{
    int list_lenth;
    oz_radioservice_network_info list[OZ_RADIOSERVICE_NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];
} oz_radioservice_network_info_list;

oz_Result oz_radioservice_init(onUnsolResponseRadio callback);

oz_Result oz_radioservice_getAttachedState(int *attached);

oz_Result oz_radioservice_getImei(char *imei);

oz_Result oz_radioservice_getRadiotechnology(oz_radioservice_rat_info *ratInfo);

oz_Result oz_radioservice_getImeisvSvn(char *imeisv);

oz_Result oz_radioservice_getNetworkName(char *name);

oz_Result oz_radioservice_getRegistrationState(oz_radioservice_registration_state *state);

oz_Result oz_radioservice_getSignalStrength(oz_radioservice_lte_signal_strength *sigLevel);

oz_Result oz_radioservice_getOperationMode(oz_radioservice_operating_mode *opMode);

oz_Result oz_radioservice_setOperationMode(oz_radioservice_operating_mode opMode);

oz_Result oz_sradioservice_factoryReset(void);

oz_Result oz_radioservice_getNetworkSelection(oz_radioservice_network_selection *netSel);

oz_Result oz_radioservice_setNetworkSelection(oz_radioservice_network_selection netSel);

oz_Result oz_radioservice_selectNetworkManual (int index);

oz_Result oz_radioservice_getNetworkInfoList(oz_radioservice_network_info_list *netlist);

oz_Result oz_radioservice_getNetworkMode(oz_radioservice_network_mode_type *modepref);

oz_Result oz_radioservice_setNetworkMode(oz_radioservice_network_mode_type modepref);

oz_Result oz_radioservice_getNrCdrxMode(oz_radioservice_nrcdrx_type *nrcdrxval);

oz_Result oz_radioservice_setNrCdrxMode(oz_radioservice_nrcdrx_type nrcdrxval);

// LGP_5G_MODULE_DEBUG_SCREEN [START]
oz_Result oz_radioservice_getDebugScreen(char* debugscreen);
// LGP_5G_MODULE_DEBUG_SCREEN [END]

oz_Result oz_radioservice_registerEvent(int aEvent);

oz_Result oz_radioservice_deregisterEvent(int aEvent);

#ifdef __cplusplus
}
#endif
