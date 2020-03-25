#pragma once

#include <stdint.h>
#include "oz_interface.h"

#define GPS_SOCKET_PATH "/tmp/socket_gpsservice_interface"

#define OZ_GPSSERVICE_GET_LOCATION 100
#define OZ_GPSSERVICE_SET_INTERVAL 101
#define OZ_GPSSERVICE_GET_INTERVAL 102
#define OZ_GPSSERVICE_START_FIX 103
#define OZ_GPSSERVICE_STOP_FIX 104
#define OZ_GPSSERVICE_GET_STATUS    105
#define OZ_GPSSERVICE_START_FACTORY 106
#define OZ_GPSSERVICE_STOP_FACTORY 107
#define OZ_GPSSERVICE_GET_FACTORY_MEASURE 108
#define OZ_GPSSERVICE_GET_TTFF 109

#define OZ_GPSSERVICE_GET_SERVICE_PARMS 120
#define OZ_GPSSERVICE_SET_SERVICE_PARMS 121
#define OZ_GPSSERVICE_GET_LOCATION_PARMS 122
#define OZ_GPSSERVICE_SET_LOCATION_PARMS 123
#define OZ_GPSSERVICE_GET_FACTORY_MEASURE_PARMS 124
#define OZ_GPSSERVICE_SET_FACTORY_MEASURE_PARMS 125

#define OZ_GPSSERVICE_NOTIFY_LOCATION_CHANGED 130
#define OZ_GPSSERVICE_NOTIFY_FACTORY_MEASURE 131
#define OZ_GPSSERVICE_NOTIFY_NMEA 132
#define OZ_GPSSERVICE_NOTIFY_SERVICE_STATUS_CHANGED 133

// status
#define  OZ_GPSSERVICE_OK 0
#define  OZ_GPSSERVICE_NOK 1

#define MAX_APN_LENGTH 127
/*
// geofence transition event
typedef uint32_t GFTransitionType;
#define OZ_GPSSERVICE_GF_TRANSITION_ENTER  (1<<0)
#define OZ_GPSSERVICE_GF_TRANSITION_EXIT  (1<<1)
#define OZ_GPSSERVICE_GF_TRANSITION_UNCERTAIN (1<<2)

typedef struct {
    uint32_t id;
    double latitude;
    double longitude;
    double radius; // in meters
} geofence_add_params_t;

typedef struct {
    uint32_t id;
    GFTransitionType event;
    double latitude;
    double longitude;
} geofence_report_t;
*/

void oz_gpsservice_rpc_handler(const void* hChHandle, int aReq, RES_OBJ aInObj, REQ_OBJ aOutObj);

