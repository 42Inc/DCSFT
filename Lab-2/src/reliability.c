#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/extralib.h"

int main(int argc, char const *argv[]) {
  int n[2] = {10, 16}, N[2][2] = {{8, 10}, {10, 16}}, m = 1, t[2] = {0, 24};
  double lambda = 0.024, mu = 0.71;
  char* filename[2] = {"./result/1.dat", "./result/2.dat"};

  for (int i = 0; i < 2; ++i) {
    FILE* fd_out = fopen(filename[i], "w");
    if (fd_out) {
      double result = reliability_func(1, 3);
      fprintf(fd_out, "result = %f\n", result);
    } else EXIT_FAILURE;
    fclose(fd_out);
  }


  return EXIT_SUCCESS;
}
