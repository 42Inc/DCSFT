#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/extralib.h"

int main(int argc, char const *argv[]) {
  int n[2] = {10, 16}, N[2][2] = {{8, 10}, {10, 16}}, m[2] = {1, 16}, t[2] = {0, 24};
  double lambda = 0.024, mu = 0.71;
  char* filename[3] = {"./result/1.dat", "./result/2.dat", "./result/3.dat"};
  FILE* fd_out;

  for (int i = 0; i < 3; ++i) {
    fd_out = fopen(filename[i], "w");
    if (fd_out) {
      double result = reliability_func(1, 3);
      fprintf(fd_out, "%f\n", result);
    } else EXIT_FAILURE;
    fclose(fd_out);
  }

  return EXIT_SUCCESS;
}
