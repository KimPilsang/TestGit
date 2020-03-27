#ifndef LOGUTIL_H
#define LOGUTIL_H

//#include <syslog.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

namespace LocationApi {
#define TS_PRINTF(format, x...)                                  \
{                                                                \
    struct timeval tv;                                           \
    struct timezone tz;                                          \
    int hh, mm, ss;                                              \
    gettimeofday(&tv, &tz);                                      \
    hh = tv.tv_sec/3600%24;                                      \
    mm = (tv.tv_sec%3600)/60;                                    \
    ss = tv.tv_sec%60;                                           \
    fprintf(stdout,"%02d:%02d:%02d.%06ld]" format "\n", hh, mm, ss, tv.tv_usec, ##x);    \
}

#define ALOGE(format, x...) TS_PRINTF("E/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define ALOGW(format, x...) TS_PRINTF("W/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define ALOGI(format, x...) TS_PRINTF("I/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define ALOGD(format, x...) TS_PRINTF("D/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define ALOGV(format, x...) TS_PRINTF("V/%s (%d): " format , "LOCATION_API", getpid(), ##x)

#define API_LOG_E(format, x...) TS_PRINTF("E/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define API_LOG_W(format, x...) TS_PRINTF("W/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define API_LOG_I(format, x...) TS_PRINTF("I/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define API_LOG_D(format, x...) TS_PRINTF("D/%s (%d): " format , "LOCATION_API", getpid(), ##x)
#define API_LOG_V(format, x...) TS_PRINTF("V/%s (%d): " format , "LOCATION_API", getpid(), ##x)

/*#define ALOGE(...) syslog(LOG_ERR,     "LOC_LOGE: " __VA_ARGS__);
#define ALOGW(...) syslog(LOG_WARNING, "LOC_LOGW: " __VA_ARGS__);
#define ALOGI(...) syslog(LOG_NOTICE,  "LOC_LOGI: " __VA_ARGS__);
#define ALOGD(...) syslog(LOG_DEBUG,   "LOC_LOGD: " __VA_ARGS__);
#define ALOGV(...) syslog(LOG_NOTICE,  "LOC_LOGV: " __VA_ARGS__);

#define API_LOG_E(...) syslog(LOG_ERR, "LOCATION_API: " __VA_ARGS__);
#define API_LOG_W(...) syslog(LOG_WARNING, "LOCATION_API: " __VA_ARGS__);
#define API_LOG_I(...) syslog(LOG_NOTICE,   "LOCATION_API: " __VA_ARGS__);
#define API_LOG_D( ...) syslog(LOG_DEBUG,   "LOCATION_API: " __VA_ARGS__);
#define API_LOG_V(...) syslog(LOG_NOTICE,   "LOCATION_API: " __VA_ARGS__);*/
}

#endif