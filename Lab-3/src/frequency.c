#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/extralib.h"

int main(int argc, char* argv[]) {
	int N = 65536;
	int m[2] = {1, 3};
	double lambda[2] = { 0.00001, 0.0000001 };
	double Theta_res, Tau_res;

	FILE* fd_out = fopen("./result/1.dat", "w");
	if (fd_out) {

		for ( int n_min = 65527 ; n_min <= 65536 ; n_min += 9 ) {
			for ( int mu = 1 ; mu <= 1000 ; mu *= 1000 ) {
				for ( int m_cnt = 0 ; m_cnt < 2 ; ++m_cnt ) {
					for ( int l_cnt = 0 ; l_cnt < 2 ; ++l_cnt ) {
						fprintf(fd_out, "%d , %d , %d , %d\t\t{ ", n_min, mu, m_cnt, l_cnt);
						printf("\n");

						for ( int n_cnt = n_min ; n_cnt <= N ; ++n_cnt ) {
							Theta_res = Theta(lambda[l_cnt], mu, n_cnt, N, m[m_cnt]);
							printf("%f\t", Theta_res);
							fprintf(fd_out, "%f\t", Theta_res);
						}
						printf("\n");
						fprintf(fd_out, "}\t\t{ ");

						for ( int n_cnt = n_min ; n_cnt <= N ; ++n_cnt) {
							Tau_res = Tau(lambda[l_cnt], mu, n_cnt, N, m[m_cnt]);
							printf("%f\t", Tau_res);
							fprintf(fd_out, "%f\t", Tau_res);
						}
						printf("\n\n");
						fprintf(fd_out, "}\n\n");
					}
				}
			}
		}
		fclose(fd_out);
	}

	return EXIT_SUCCESS;
}
