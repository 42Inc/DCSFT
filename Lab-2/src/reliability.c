#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/extralib.h"

int main(int argc, char const *argv[]) {
  // N = 10; n ∈{8, 9, 10}; lambda = 0,024 1/ч; mu = 0,71 1/ч; m = 1;
  //t = 0, 2, 4, …, 24 ч.
  int N = 10, m = 1;
  double lambda = 0.024, mu = 0.71;
  for (int n = 8; n <= 10; n++)
  {
    printf("\nn = %d\n", n);
    for (int t = 0; t <= 24; t += 2)
      printf("R = %f\n", R(n, t, m, N, mu, lambda));
  }

  //N = 16; n ∈{ 10, 11, …, 16};
  N = 16;

  for (int n = 10; n <= 16; n++)
  {
    printf("\nn = %d\n", n);
    for (int t = 0; t <= 24; t += 2)
      printf("Q = %f\n", Q_(n, N, m, mu, lambda, t));
  }

  for (m = 1; m <= 16; m++)
  {
    printf("\nm = %d\n", m);
    for (int n = 11; n <= 16; n++)
    {
      printf("R = %f\n", R(n, 0, m, N, mu, lambda));
      printf("S = %f\n", S(n, m, mu, lambda));
    }
  }
  return EXIT_SUCCESS;
}
