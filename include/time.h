#ifndef _TIME_H
#define _TIME_H

#include <stdint.h>
#include <stddef.h>

typedef int64_t time_t;
typedef int64_t clock_t;

struct tm {
    int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst;
};

time_t time(time_t *tloc);
clock_t clock(void);

#endif