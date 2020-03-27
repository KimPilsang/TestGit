#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#ifndef TAG
#define TAG __func__
#endif

#define OZ_LOG_INIT() \
             setlogmask(LOG_UPTO(LOG_DEBUG)); \
             openlog (TAG, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER | LOG_NEWS | LOG_AUTH)

#ifndef __OZ_PRINTF__
#define OZ_LOGD(fmt,...) syslog(LOG_ERR, "(%s:%d) " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#define OZ_LOGE(fmt,...) syslog(LOG_ERR, "(%s:%d) " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define OZ_LOG(fmt,...) \
    do {                \
        char msg[2048] = {0,}; \
        snprintf(msg, sizeof(msg), fmt, ## __VA_ARGS__); \
        printf("%s %d: %lu: [%s] %s\n",__func__, getpid(), syscall(SYS_gettid), TAG, msg); \
    } while (0)
#define OZ_LOGD OZ_LOG
#define OZ_LOGE OZ_LOG
#endif

#define UNSOL_SOCKET_POSTFIX "_Unsol"

typedef enum {
    OZ_OK = 0,
    OZ_NOT_PERMITTED,
    OZ_TIMEOUT,
    OZ_FRORMAT_ERROR,
    OZ_CLOSED,
    OZ_BUSY,
    OZ_UNSUPPORTED,
    OZ_IO_ERROR,
    OZ_UNAVAILABLE,
    OZ_TERMINATED
}oz_Result;

typedef enum {
    OZ_OFF = 0,
    oz_ON,
} oz_OnOff;

#define TRUE 1
#define FALSE 0
