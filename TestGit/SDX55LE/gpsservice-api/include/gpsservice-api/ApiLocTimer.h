#ifndef APILOC_TIMER_H
#define APILOC_TIMER_H

#include <LocTimer.h>

namespace LocationApi {

class ApiLocTimer : public LocTimer {
public:
    ApiLocTimer() : LocTimer(), mStarted(false) {}
    inline ~ApiLocTimer() { stop(); }
    inline void set(const time_t waitTimeSec, const Runnable& runable) {
        mWaitTimeInMs = waitTimeSec * 1000;
        mRunnable = runable;
    }
    inline void start() {
        mStarted = true;
        LocTimer::start(mWaitTimeInMs, false);
    }
    inline void start(const time_t waitTimeSec) {
        mWaitTimeInMs = waitTimeSec * 1000;
        start();
    }
    inline void stop() {
        if (mStarted) {
            LocTimer::stop();
            mStarted = false;
        }
    }
    inline void restart() { stop(); start(); }
    inline void restart(const time_t waitTimeSec) { stop(); start(waitTimeSec); }
    inline bool isStarted() { return mStarted; }

private:
    // Override
    inline virtual void timeOutCallback() override {
        mStarted = false;
        mRunnable();
    }

private:
    time_t mWaitTimeInMs;
    Runnable mRunnable;
    bool mStarted;

};

}
#endif