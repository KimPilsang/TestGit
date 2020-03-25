#ifndef APIUTIL_H
#define APIUTIL_H

namespace LocationApi {

uint64_t getRealTimeNsec();
uint64_t getUpTimeSec();
int timeval_difference (struct timeval *result, struct timeval *x, struct timeval *y);
bool setRequiredPermToLoadHAL();

} // LocationApi

#endif