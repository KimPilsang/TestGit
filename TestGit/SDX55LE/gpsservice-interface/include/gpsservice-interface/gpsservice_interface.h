#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "oz_common.h"

typedef enum {
  OZ_GPSSERVICE_GNSS_NO_FIX = 0,
  OZ_GPSSERVICE_GNSS_FIX,
  OZ_GPSSERVICE_WPS_NO_FIX,
  OZ_GPSSERVICE_WPS_FIX,
  OZ_GPSSERVICE_UNKNOWN
} oz_gpsservice_result_type;

typedef struct {
  oz_gpsservice_result_type result;
  double timestampUtc;
  double latitude;
  double longitude;
  double altitude;
  double speed;
  double bearing;
  double accuracy;
  double verticalAccuracy;
  double speedAccuracy;
  double bearingAccuracy;
} oz_gpsservice_location_info;

// enable/disable
typedef enum {
    OZ_GPSSERVICE_DISABLE = 0,
    OZ_GPSSERVICE_INVALID = 0,
    OZ_GPSSERVICE_ENABLE = 1,
    OZ_GPSSERVICE_VALID = 1
} oz_gpsservice_flags_type;
 
typedef enum {
    OZ_GPSSERVICE_HOT_START = 0,
    OZ_GPSSERVICE_WARM_START = 1,
    OZ_GPSSERVICE_COLD_START = 2,
} oz_gpsservice_start_flags_type;

// status
typedef enum {
    OZ_GPSSERVICE_STATUS_NONE = 0,
    OZ_GPSSERVICE_STATUS_SESSION_BEGIN,
    OZ_GPSSERVICE_STATUS_SESSION_END,
    OZ_GPSSERVICE_STATUS_ENGINE_ON,
    OZ_GPSSERVICE_STATUS_ENGINE_OFF,
    OZ_GPSSERVICE_STATUS_ENGINE_FACTORY_ON,
    OZ_GPSSERVICE_STATUS_UNKNOWN
} oz_gpsservice_status_type;

// position mode
typedef enum {
  OZ_GPSSERVICE_POSITION_MODE_STANDALONE = 0,
  OZ_GPSSERVICE_POSITiON_MODE_MSB,
  OZ_GPSSERVICE_POSITiON_MODE_MSA
} oz_gpsservice_position_mode_type;

// recurrence
typedef enum {
  OZ_GPSSERVICE_POSITION_TRACKING = 0,
  OZ_GPSSERVICE_POSITION_SINGLE
} oz_gpsservice_recurrence_type;

typedef struct {
    oz_gpsservice_flags_type enabled_nmea_report;
    oz_gpsservice_flags_type enabled_debug;
} oz_gpsservice_params;

typedef struct {
    oz_gpsservice_start_flags_type start_flag;
    oz_gpsservice_position_mode_type position_mode;
    oz_gpsservice_recurrence_type recurrence;
    int interval;
    int accuracy;
    int response_time;
} oz_gpsservice_loc_params;

typedef struct {
    oz_gpsservice_flags_type valid;
    double timestampUtc;
    int svid;
    int cn0;
} oz_gpsservice_satellite_info;

typedef struct {
    oz_gpsservice_satellite_info gps;
    oz_gpsservice_satellite_info glonass;
    oz_gpsservice_satellite_info beidou;
    oz_gpsservice_satellite_info gallieo;
} oz_gpsservice_factory_report_info;

typedef struct {
    int max_timeout_seconds;
} oz_gpsservice_factory_params;

#define NMEA_MAXSIZE 256
typedef struct {
    double timestampUtc;
    int nmea_len;
    char nmea_str[NMEA_MAXSIZE];
} oz_gpsservice_nmea_report_info;

typedef void (*onUnsolResponseGps)(int response, void* data);

oz_Result oz_gpsservice_init(onUnsolResponseGps callback);

oz_Result oz_gpsservice_getLocation(oz_gpsservice_location_info *loc);

oz_Result oz_gpsservice_startFix(void);

oz_Result oz_gpsservice_stopFix(void);

oz_Result oz_gpsservice_setInterval(int inteval);

oz_Result oz_gpsservice_getInterval(int *interval);

oz_Result oz_gpsservice_getTTFF(int *ttff);

oz_Result oz_gpsservice_getStatus(oz_gpsservice_status_type *status);

oz_Result oz_gpsservice_setParams(oz_gpsservice_params params);

oz_Result oz_gpsservice_getParams(oz_gpsservice_params *params);

oz_Result oz_gpsservice_setLocParams(oz_gpsservice_loc_params params);

oz_Result oz_gpsservice_getLocParams(oz_gpsservice_loc_params *params);

oz_Result oz_gpsservice_startFactory(void);

oz_Result oz_gpsservice_stopFactory(void);

oz_Result oz_gpsservice_setFactoryParams(oz_gpsservice_factory_params params);

oz_Result oz_gpsservice_getFactoryParams(oz_gpsservice_factory_params *params);

oz_Result oz_gpsservice_getFactoryMeasure(oz_gpsservice_factory_report_info *measure);

//Register Event
oz_Result oz_gpsservice_registerEvent(int aEvent);
//Deregister Event
oz_Result oz_gpsservice_deregisterEvent(int aEvent);


#ifdef __cplusplus
}
#endif
