#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../measurement.h"

int main()
{
    timestamp_t t1 = get_timestamp();
    sleep(1);
    timestamp_t t2 = get_timestamp();
    printf("%lfs\n", get_interval(t1, t2, MEASUREMENT_SECOND));
    sleep(2);
    printf("%lfs\n", get_interval(t2, -1, MEASUREMENT_SECOND));
    return 0;
}
