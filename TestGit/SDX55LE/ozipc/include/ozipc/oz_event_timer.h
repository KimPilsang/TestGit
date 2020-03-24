
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

typedef void (*TimedCallback) (void* aParam);

typedef void (*EventCallback) (void* aParam, int aLen);

void* oz_setTimedCallback (TimedCallback callback, void *param,
                                struct timeval *relativeTime);
void oz_timer_roof_init();

void oz_register_event(int aEventId, EventCallback aCallbakc);

void oz_trigger_event(int aEvent, void* aParam, int aLen);

#ifdef __cplusplus
}
#endif

