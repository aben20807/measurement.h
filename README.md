# Download

```bash
$ curl -fLo ./measurement.h https://raw.githubusercontent.com/aben20807/measurement.h/master/measurement.h
```

# Usage

## Import

```c
#include "measurement.h"
```

## Data types

+ `timestamp_t`: `double`
+ `time_interval_t`: `double`

## Constants (Used for unit)

+ C++

```cpp
Unit::NANOSECOND
Unit::MICROSECOND
Unit::MILLISECOND
Unit::SECOND
Unit::MINUTE
Unit::HOUR
Unit::DAY
```

+ C

```c
MEASUREMENT_NANOSECOND
MEASUREMENT_MICROSECOND
MEASUREMENT_MILLISECOND
MEASUREMENT_SECOND
MEASUREMENT_MINUTE
MEASUREMENT_HOUR
MEASUREMENT_DAY
```

## Functions

+ C++

```cpp
timestamp_t get_timestamp()
time_interval_t get_interval(timestamp_t before, timestamp_t after, Unit unit=Unit::SECOND)
time_interval_t get_interval(timestamp_t before, Unit unit=Unit::SECOND)
```

+ C

```c
timestamp_t get_timestamp()
time_interval_t get_interval(timestamp_t before, timestamp_t after, Unit unit)
```

+ Note:
  + If `after` is passed as `-1` then it means to get the interval from `before` to now.

# License

+ MIT
