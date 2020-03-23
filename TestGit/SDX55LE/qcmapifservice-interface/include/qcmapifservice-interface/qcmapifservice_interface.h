#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "oz_common.h"
#include "qualcomm_mobile_access_point_msgr_v01.h"

typedef void (*onUnsolResponseQcmapif)(int response, const void* data);

#define NULLSTR "nullstr"

typedef struct
{
  uint8_t port_protocol; //0:TCP, 1:UDP
  uint16_t from_port_num;
  uint32_t to_ip_addr;
  uint16_t to_port_num;
}oz_qcmapifservice_router_port_mapping_entry_type;

typedef struct
{
  int list_cnt;
  oz_qcmapifservice_router_port_mapping_entry_type port_mapping_list[50];
}oz_qcmapifservice_router_port_mapping_type;

oz_Result oz_qcmapifservice_init(onUnsolResponseQcmapif callback);

oz_Result oz_qcmapifservice_setMobileAP(int enabled, int *qcmapResult);

oz_Result oz_qcmapifservice_getMobileAP(int *enabled, int *qcmapResult);

oz_Result oz_qcmapifservice_getDMZ(char *dmzIP, int *qcmapResult);

oz_Result oz_qcmapifservice_addDMZ(char *dmzIP, int *qcmapResult);

oz_Result oz_qcmapifservice_delDMZ(char *dmzIP, int *qcmapResult);

oz_Result oz_qcmapifservice_get_wanPingBlock(int *pingBlock, int *qcmapResult);

oz_Result oz_qcmapifservice_set_wanPingBlock(int pingBlock, int *qcmapResult);

oz_Result oz_qcmapifservice_getProfile(int *profileId, int *qcmapResult);

oz_Result oz_qcmapifservice_setProfile(int profileId, int *qcmapResult);

oz_Result oz_qcmapifservice_getWanState(int *v4State, int *v6State, int *qcmapResult);

oz_Result oz_qcmapifservice_connectBackHaul(int *qcmapResult);

oz_Result oz_qcmapifservice_disconnectBackHaul(int *qcmapResult);

oz_Result oz_qcmapifservice_getDataEnabled(int *enabled, int *qcmapResult);

oz_Result oz_qcmapifservice_setDataEnabled(int enabled, int *qcmapResult);

oz_Result oz_qcmapifservice_getRoamingDataEnabled(int *enabled, int *qcmapResult);

oz_Result oz_qcmapifservice_setRoamingDataEnabled(int enabled, int *qcmapResult);

oz_Result oz_qcmapifservice_updateApnInfo(char *apn, char *name);

oz_Result oz_qcmapifservice_getApnName(char *name);

oz_Result oz_qcmapifservice_getProfileName(char *profileName);

oz_Result oz_qcmapifservice_getPortForwading(oz_qcmapifservice_router_port_mapping_type *pParam, int *qcmapResult);

oz_Result oz_qcmapifservice_addPortForwading(oz_qcmapifservice_router_port_mapping_entry_type pParam, int *qcmapResult);

oz_Result oz_qcmapifservice_delPortForwading(oz_qcmapifservice_router_port_mapping_entry_type pParam, int *qcmapResult);

oz_Result oz_qcmapifservice_registerEvent(int aEvent);

oz_Result oz_qcmapifservice_deregisterEvent(int aEvent);

oz_Result oz_qcmapifservice_getNetworkMode(int *modepref, int *qcmapResult);

oz_Result oz_qcmapifservice_setNetworkMode(int modepref, int *qcmapResult);

oz_Result oz_qcmapifservice_getNrCdrxMode(int *nrcdrxval, int *qcmapResult);

oz_Result oz_qcmapifservice_setNrCdrxMode(int nrcdrxval, int *qcmapResult);

oz_Result oz_qcmapifservice_getDebugScreen(char *debugscreen, int *qcmapResult); //LGP_5G_MODULE_DEBUG_SCREEN - QCMAP

oz_Result oz_qcmapifservice_getRadioTechnology(int *radiotech, int *qcmapResult);

oz_Result oz_qcmapifservice_getCurrentNetworkName(char *networkname);

oz_Result oz_qcmapifservice_activateWlan(int *qcmapResult);

oz_Result oz_qcmapifservice_enableWlan(int enabled, int privileged_clientint, int *qcmapResult);

oz_Result oz_qcmapifservice_setWlanConfig(qcmap_msgr_wlan_mode_enum_v01 wlan_mode,
                                                   qcmap_msgr_access_profile_v01 guest_ap_access_profile,
                                                   qcmap_msgr_station_mode_config_v01 station_config,
                                                   int *qcmapResult,
                                                   qcmap_msgr_guest_profile_config_v01 *guest_profile);

#ifdef __cplusplus
}
#endif
