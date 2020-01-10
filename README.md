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

```c
Unit::NANOSECOND
Unit::MICROSECOND
Unit::MILLISECOND
Unit::SECOND
Unit::MINUTE
Unit::HOUR
Unit::DAY
```

## Functions

```c
timestamp_t get_timestamp()
time_interval_t get_interval(timestamp_t before, timestamp_t after, Unit unit=Unit::SECOND)
time_interval_t get_interval(timestamp_t before, Unit unit=Unit::SECOND)
```

# License

+ MIT
