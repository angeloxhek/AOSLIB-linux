#ifndef _SYS_TIME_H
#define _SYS_TIME_H

#include <stdint.h>
#include <stddef.h>
#include <time.h>

struct timeval {
    time_t tv_sec;
    int64_t tv_usec;
};

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

int gettimeofday(struct timeval *tv, struct timezone *tz);

#endif