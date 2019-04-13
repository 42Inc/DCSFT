#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/extralib.h"

int main(int argc, char const *argv[]) {
  // N = 10; n ∈{8, 9, 10}; lambda = 0,024 1/ч; mu = 0,71 1/ч; m = 1;
  //t = 0, 2, 4, …, 24 ч.
  int N = 10, m = 1;
  double lambda = 0.024, mu = 0.71;

  FILE* f_out = fopen("./result/1.dat", "w");
	if (f_out) {
		fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
		for (int t = 0; t <= 24; t += 4)
			fprintf(f_out, "\"t = %d/hours\"    ", t);
		fprintf(f_out, "\n");

		for (int n = 8; n <= 10; n++) {
			fprintf(f_out, "%d    ", n);
			for (int t = 0; t <= 24; t += 4)
				fprintf(f_out, "%.6f    ", R(n, t, m, N, mu, lambda));
			fprintf(f_out, "\n");
		}
		fclose(f_out);
	}

  //N = 16; n ∈{ 10, 11, …, 16};
  N = 16;
  f_out = fopen("./result/2.dat", "w");
  if (f_out) {
    fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
    for (int t = 0; t <= 24; t += 2)
      fprintf(f_out, "\"t = %d/hours\"    ", t);
    fprintf(f_out, "\n");

    for (int n = 10; n <= 16; ++n) {
      fprintf(f_out, "%d    ", n);
      for (int t = 0; t <= 24; t += 2)
        fprintf(f_out, "%.6f    ", Q_(n, N, m, mu, lambda, t));
      fprintf(f_out, "\n");
    }
    fclose(f_out);
  }

  f_out = fopen("./result/3.dat", "w");
  if (f_out) {
    fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
    for (m = 1; m <= 16; ++m)
      fprintf(f_out, "\"m = %d\"    ", m);
    fprintf(f_out, "\n");

    for (int n = 11; n <= 16; ++n) {
      fprintf(f_out, "%d    ", n);
      for (m = 1; m <= 16; ++m)
        fprintf(f_out, "%.6f    ", S(n, m, mu, lambda));
      fprintf(f_out, "\n");
    }
    fclose(f_out);
  }

  return EXIT_SUCCESS;
}
