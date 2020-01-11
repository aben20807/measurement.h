#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../../measurement.h"
using namespace std;

int main(int argc, char* argv[]) {
  int FROM = 1000000;
  int STEP = 1000000;
  int TO = 10000000;
  // Same operation is measured more than one time and the results are averaged later
  int MEASURE_TIMES = 10;
  string opt(argv[1]);
  for (int nn = FROM, fc = 0; nn <= TO; nn += STEP, fc++) {
    fprintf(stderr, "%d\n", nn);
    string filename1("f1_O" + opt + "_" + to_string(fc) + ".txt");
    string filename2("f2_O" + opt + "_" + to_string(fc) + ".txt");
    FILE* f1 = fopen(filename1.c_str(), "w");
    FILE* f2 = fopen(filename2.c_str(), "w");
    for (int mt = 0; mt < MEASURE_TIMES; mt++) {
      vector<int> v1;
      vector<int> v2;
      vector<int> v3;
      vector<int> v4;

      // Make sure that the operations are not vanished by the compiler optimization
      srand(5);
      int c = 1;
      for (int i = 0; i < nn; i++) {
        int r = rand() % nn;
        v1.push_back(r);
        v2.push_back(r);
        v3.push_back(0);
        v4.push_back(0);
      }

      // Used to compare using size() with decreasing an integer in a loop
      timestamp_t t1 = get_timestamp();

      while (v1.size()) {
        v3[v1.back()] = c;
        v1.pop_back();
      }

      timestamp_t t2 = get_timestamp();

      int s = v2.size();
      while (s--) {
        v4[v2.back()] = c;
        v2.pop_back();
      }

      timestamp_t t3 = get_timestamp();

      // Verify the execution and let the operation can not be skipped
      long int sum3 = 0, sum4 = 0;
      for (int i = 0; i < nn; i++) {
        sum3 += v3[i];
        sum4 += v4[i];
      }

      // Output to files for the visualization
      fprintf(stdout, "1:\n");
      fprintf(stdout, "%ld\n", v1.size());
      fprintf(f1, "%lf\n", get_interval(t1, t2, Unit::SECOND));
      fprintf(stdout, "%ld\n", sum3);
      fprintf(stdout, "2:\n");
      fprintf(stdout, "%ld\n", v2.size());
      fprintf(f2, "%lf\n", get_interval(t2, t3, Unit::SECOND));
      fprintf(stdout, "%ld\n", sum4);
    }
    fclose(f1);
    fclose(f2);
  }
  return 0;
}
