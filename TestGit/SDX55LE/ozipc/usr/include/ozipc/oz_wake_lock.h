#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int oz_power_wake_lock(const char* aModule);
int oz_power_wake_unlock(const char* aModule);

#ifdef __cplusplus
}
#endif

