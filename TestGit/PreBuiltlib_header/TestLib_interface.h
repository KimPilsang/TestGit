#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "oz_common.h"

typedef enum {
  OZ_DATASERVICE_APN_IPV4 = 4,
  OZ_DATASERVICE_APN_IPV6 = 6,
  OZ_DATASERVICE_APN_IPV4V6 = 10,
  OZ_DATASERVICE_APN_MAX
} oz_dataservice_ip_version;

typedef enum {
  OZ_DATASERVICE_AUTH_NONE,
  OZ_DATASERVICE_AUTH_PAP,
  OZ_DATASERVICE_AUTH_CHAP,
  OZ_DATASERVICE_AUTH_BOTH,
  OZ_DATASERVICE_AUTH_MAX
} oz_dataservice_auth_type;

typedef enum {
  OZ_DATASERVICE_APN_ATTACH_TYPE = 0,
  OZ_DATASERVICE_APN_INTERNET_TYPE = 1,
  OZ_DATASERVICE_APN_ADMIN_TYPE = 2,
  OZ_DATASERVICE_APN_IMS_TYPE = 3,
  OZ_DATASERVICE_APN_DUN_TYPE = 4,
  OZ_DATASERVICE_APN_CARRIER_TYPE = 5,
  OZ_DATASERVICE_APN_INVALID_TYPE = 6
} oz_dataservice_apn_type;

typedef enum {
  OZ_DATASERVICE_CALL_IDLE,
  OZ_DATASERVICE_CALL_CONNECTING,
  OZ_DATASERVICE_CALL_CONNECTED,
  OZ_DATASERVICE_CALL_DISCONNECTING,
  OZ_DATASERVICE_CALL_MAX
} oz_dataservice_call_state;

typedef void (*onUnsolResponseData)(int id, oz_dataservice_apn_type type, oz_dataservice_call_state state);

oz_Result oz_dataservice_init(onUnsolResponseData callback);

oz_Result oz_dataservice_requestDataConnect(oz_dataservice_apn_type type, oz_dataservice_call_state *state);

oz_Result oz_dataservice_releaseDataConnection(oz_dataservice_apn_type type);

oz_Result oz_dataservice_getDataConnectionState(oz_dataservice_call_state *state);

oz_Result oz_dataservice_getDataConnectionStateType(oz_dataservice_apn_type type, oz_dataservice_call_state *state);

oz_Result oz_dataservice_updateApnInfo(oz_dataservice_apn_type type, int ipVersion, int auth, char *apn, char *username, char *password, char *profileName);

oz_Result oz_dataservice_getApnName(oz_dataservice_apn_type type, char *name);

oz_Result oz_dataService_getIpAddress(oz_dataservice_apn_type type, char *addr);

oz_Result oz_dataService_getRouteIpAddress(oz_dataservice_apn_type type, char *addr);

oz_Result oz_dataservice_getProfileId(oz_dataservice_apn_type type, int *profileId);

oz_Result oz_dataservice_getIpVersion(oz_dataservice_apn_type type, oz_dataservice_ip_version *ipVersion);

oz_Result oz_dataservice_getAuthType(oz_dataservice_apn_type type, oz_dataservice_auth_type *auth);

oz_Result oz_dataservice_getUserName(oz_dataservice_apn_type type, char *userName);

oz_Result oz_dataservice_getPassword(oz_dataservice_apn_type type, char *password);

oz_Result oz_dataservice_getProfileName(oz_dataservice_apn_type type, char *profileName);

oz_Result oz_dataservice_getRetryInterval(char *interval);

oz_Result oz_dataservice_setRetryInterval(char *interval);

oz_Result oz_dataservice_registerEvent(int aEvent);

oz_Result oz_dataservice_deregisterEvent(int aEvent);

#ifdef __cplusplus
}
#endif
