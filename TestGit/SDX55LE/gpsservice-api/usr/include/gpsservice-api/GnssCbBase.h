#ifndef GNSSCBBASE_H
#define GNSSCBBASE_H

#include <mutex>
#include <loc_gps.h>
#include <gps_extended.h>

using std::mutex;
using lock_guard = std::lock_guard<mutex>;

namespace LocationApi {

class GnssCbBase {
public:
    GnssCbBase() = default;
    virtual ~GnssCbBase() = default;

    // gnss
    virtual void gnssLocationCb(Location& location);
    virtual void gnssStatusCb(uint32_t status);
    virtual void gnssSvStatusCb(GnssSvNotification& gnssSvNotify);
    virtual void gnssNmeaCb(uint64_t timestamp, const char* nmea, int length);
    virtual void gnssMeasurementsCb(GnssMeasurementsNotification& gnssMeasurementsNotification);
    virtual void gnssDataCb(GnssDataNotification& gnssDataNotify);
    virtual void gnssSetCapabilitiesCb(uint32_t capabilities);
    virtual void gnssRequestUtcTimeCb();
    virtual void gnssNiNotifyCb(uint32_t id, GnssNiNotification& gnssNinotification);
    virtual void gnssLocInfoNotifCb(GnssLocationInfoNotification gnssLocInfoNotif);

    // flp
    virtual void batchingCb(size_t /*count*/, Location* /*location*/) {}
    virtual void startBatchingCb(LocationError /*error*/) {}
    virtual void stopBatchingCb(LocationError /*error*/) {}
    virtual void updateBatchingCb(LocationError /*error*/) {}
    virtual void getBatchedLocationCb(LocationError /*error*/) {}
    virtual void startTrackingCb(LocationError /*error*/) {}
    virtual void stopTrackingCb(LocationError /*error*/) {}
    virtual void updateTrackingCb(LocationError /*error*/) {}

    // geofence
    virtual void geofenceBreachCb(uint32_t /*id*/, Location /*location*/,
            GeofenceBreachType /*transition*/, uint64_t /*timeStamp*/) {}
    virtual void geofenceStatusCb(GeofenceStatusAvailable /*status*/) {}
    virtual void addGeofencesCb(uint32_t /*id*/, LocationError /*error*/) {}
    virtual void removeGeofencesCb(uint32_t /*id*/, LocationError /*error*/) {}
    virtual void pauseGeofencesCb(uint32_t /*id*/, LocationError /*error*/) {}
    virtual void resumeGeofencesCb(uint32_t /*id*/, LocationError /*error*/) {}
    virtual void modifyGeofencesCb(uint32_t /*id*/, LocationError /*error*/) {}
};

}
#endif //GNSSCBBASE_H