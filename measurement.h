#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include <time.h>

#define CONCAT_(A, B) A ## B
#define CONCAT(A, B) CONCAT_(A, B)
#ifdef __cplusplus
    #define DEFAULT_VALUE(value) =value
    #define ENUM_ITEM(itm) itm
    #define ENUM_CASE(prefix, cas) prefix::cas
#else
    #define DEFAULT_VALUE(value)
    #define C_PREFIX MEASUREMENT_ /* change this if there is any conflict */
    #define ENUM_ITEM(itm) CONCAT(C_PREFIX, itm)
    #define ENUM_CASE(prefix, cas) CONCAT(C_PREFIX, cas)
#endif

typedef enum {
    ENUM_ITEM(NANOSECOND) = 1000000000,
    ENUM_ITEM(MICROSECOND) = 1000000,
    ENUM_ITEM(MILLISECOND) = 1000,
    ENUM_ITEM(SECOND) = 1,
    ENUM_ITEM(MINUTE) = 2,
    ENUM_ITEM(HOUR) = 3,
    ENUM_ITEM(DAY) = 4,
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

time_interval_t get_interval(timestamp_t before, timestamp_t after DEFAULT_VALUE(-1), Unit unit DEFAULT_VALUE(Unit::SECOND))
{
    timestamp_t now = get_timestamp();
    double scale = unit;
    switch (unit) {
        case ENUM_CASE(Unit, MINUTE):
            scale = 0.01666666666666666666;
            break;
        case ENUM_CASE(Unit, HOUR):
            scale = 0.0002777777777777777777;
            break;
        case ENUM_CASE(Unit, DAY):
            scale = 1.15740740740740740e-05;
            break;
        case ENUM_CASE(Unit, NANOSECOND):
        case ENUM_CASE(Unit, MICROSECOND):
        case ENUM_CASE(Unit, MILLISECOND):
        case ENUM_CASE(Unit, SECOND):
            scale = unit;
            break;
        default:
            printf("ERROR: unknown unit!\n");
            exit(1);
    }
    if (after == -1) {
        return (now - before) * scale;
    }
    return (after - before) * scale;
}

#ifdef __cplusplus
time_interval_t get_interval(timestamp_t before, Unit unit=Unit::SECOND)
{
    return get_interval(before, get_timestamp(), unit);
}
#endif

#endif /* MEASUREMENT_H */
