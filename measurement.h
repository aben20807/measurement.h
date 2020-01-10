#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include <time.h>

typedef enum {
    NANOSECOND  = 1000000000,
    MICROSECOND  = 1000000,
    MILLISECOND  = 1000,
    SECOND   = 1,
    MINUTE   = 2,
    HOUR   = 3,
    DAY   = 4,
} Unit;

typedef double timestamp_t;
typedef double time_interval_t;

timestamp_t get_timestamp()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    double sec;
    sec = ts.tv_nsec;
    sec /= 1e9;
    sec += ts.tv_sec;

    return sec;
}

time_interval_t get_interval(timestamp_t before, timestamp_t after, Unit unit=Unit::SECOND)
{
    double scale = unit;
    switch (unit) {
        case Unit::MINUTE:
            scale = 0.01666666666666666666;
            break;
        case Unit::HOUR:
            scale = 0.0002777777777777777777;
            break;
        case Unit::DAY:
            scale = 1.15740740740740740e-05;
            break;
        case Unit::NANOSECOND:
        case Unit::MICROSECOND:
        case Unit::MILLISECOND:
        case Unit::SECOND:
            scale = unit;
            break;
        default:
            printf("ERROR: unknown unit!\n");
            exit(1);
    }
    return (after - before) * scale;
}

time_interval_t get_interval(timestamp_t before, Unit unit=Unit::SECOND)
{
    return get_interval(before, get_timestamp(), unit);
}

#endif /* MEASUREMENT_H */
