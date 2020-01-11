#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "../../measurement.h"
using namespace std;

int main() {
  timestamp_t t1 = get_timestamp();
  sleep(1);
  timestamp_t t2 = get_timestamp();
  printf("%lfs\n", get_interval(t1, t2));
  sleep(2);
  printf("%lfs\n", get_interval(t2, Unit::SECOND));
  return 0;
}
