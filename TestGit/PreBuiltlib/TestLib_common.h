#pragma once

#include "oz_interface.h"

//For RPC - No Update
//For Backup & Restore - "" (null string)
#define NULLSTR "nullstr"

#define DATASERVICE_SOCKET_PATH "/tmp/socket_dataservice_interface"

#define OZ_DATASERVICE_REQUEST_DATACONNECT                 1000
#define OZ_DATASERVICE_RELEASE_DATACONNECTION              1001
#define OZ_DATASERVICE_GET_DATACONNECTION_STATE            1002
#define OZ_DATASERVICE_GET_DATACONNECTION_STATE_TYPE       1003
#define OZ_DATASERVICE_UPDATE_APN_INFO                     1004
#define OZ_DATASERVICE_GET_APN_NAME                        1005
#define OZ_DATASERVICE_GET_IP_ADDRESS                      1006
#define OZ_DATASERVICE_GET_ROUTE_IP_ADDRESS                1007
#define OZ_DATASERVICE_GET_PROFILE_ID                      1008
#define OZ_DATASERVICE_GET_IP_VERSION                      1009
#define OZ_DATASERVICE_GET_AUTH                            1010
#define OZ_DATASERVICE_GET_USERNAME                        1011
#define OZ_DATASERVICE_GET_PASSWORD                        1012
#define OZ_DATASERVICE_GET_PROFILE_NAME                    1013
#define OZ_DATASERIVCE_GET_RETRY_INTERVAL                  1014
#define OZ_DATASERIVCE_SET_RETRY_INTERVAL                  1015
#define OZ_DATASERVICE_RPC_MAX                             OZ_DATASERIVCE_SET_RETRY_INTERVAL

#define OZ_DATASERVICE_NOTIFY_DATACONNECTION_STATECHANGED  2000
#define OZ_DATASERVICE_APN_CHANGED                         2001

void oz_dataservice_rpc_handler(const void* hChHandle, int aReq, RES_OBJ aInObj, REQ_OBJ aOutObj);

