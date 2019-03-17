#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/extralib.h"

int main(int argc, char* argv[]) {
	double lambda = 0.00001;
	int N = 65536;
	int m = 1;

	FILE* f_out = fopen("./result/1.dat", "w");
	if (f_out) {
		fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
		for (int mu = 1; mu != 10000; mu *= 10)
			fprintf(f_out, "\"mu = %d 1/hours\"    ", mu);
		fprintf(f_out, "\n");

		for (int n = 65527; n <= N; ++n) {
			fprintf(f_out, "%d    ", n);
			for (int mu = 1; mu != 10000; mu *= 10)
				fprintf(f_out, "%.6f    ", Theta(lambda, mu, n, N, m));
			fprintf(f_out, "\n");
		}
		fclose(f_out);
	}

	f_out = fopen("./result/2.dat", "w");
	double mu = 1.0;
	if (f_out) {
		fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
		for (int i = 5; i != 10; ++i)
			fprintf(f_out, "\"Lambda = 1E-%d 1/hours\"    ", i);
		fprintf(f_out, "\n");

		for (int n = 65527; n <= N; ++n) {
			fprintf(f_out, "%d    ", n);
			for (int i = -5; i >= -9; --i)
				fprintf(f_out, "%.6f    ", Theta(pow(10.0, i), mu, n, N, m));
			fprintf(f_out, "\n");
		}
		fclose(f_out);
	}

	f_out = fopen("./result/3.dat", "w");
	lambda = 0.00001;
	if (f_out) {
		fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
		for (int i = 1; i != 5; ++i)
			fprintf(f_out, "\"m = %d\"    ", i);
		fprintf(f_out, "\n");

		for (int n = 65527; n <= N; ++n) {
			fprintf(f_out, "%d    ", n);
			for (int i = 1; i <= 4; ++i)
				fprintf(f_out, "%.6f    ", Theta(lambda, mu, n, N, i));
			fprintf(f_out, "\n");
		}
		fclose(f_out);
	}

	f_out = fopen("./result/4.dat", "w");
	lambda = 0.001;
	N = 1000;
	int mus[] = { 1, 2, 4, 6 };
	if (f_out) {
		fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
		for (int i = 0; i != 5; ++i)
			fprintf(f_out, "\"Lambda = %d hours^-1\"    ", mus[i]);
		fprintf(f_out, "\n");

		for (int n = 900; n <= N; n += 10) {
			fprintf(f_out, "%d    ", n);
			for (int i = 0; i < 4; ++i)
				fprintf(f_out, "%.6f    ", Tau(lambda, mus[i], n, N, m));
			fprintf(f_out, "\n");
		}
		fclose(f_out);
	}

	f_out = fopen("./result/5.dat", "w");
	mu = 1.0;
	N = 8192;
	if (f_out) {
		fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
		for (int i = 5; i != 10; ++i)
			fprintf(f_out, "\"Lambda = 1E-%d 1/hours\"    ", i);
		fprintf(f_out, "\n");

		for (int n = 8092; n <= N; n += 10) {
			fprintf(f_out, "%d    ", n);
			for (int i = -5; i>= -9; --i)
				fprintf(f_out, "%.6f    ", Tau(pow(10.0, i), mu, n, N, m));
			fprintf(f_out, "\n");
		}
		fclose(f_out);
	}

	f_out = fopen("./result/6.dat", "w");
	lambda = 0.00001;
	N = 8202;
	N = 8192;
	if (f_out) {
		fprintf(f_out, "\"Number n of elementary machines in base subsystem\"    ");
		for (int i = 1; i != 5; ++i)
			fprintf(f_out, "\"m = %d\"    ", i);
		fprintf(f_out, "\n");

		for (int n = 8092; n <= N; n += 10) {
			fprintf(f_out, "%d    ", n);
			for (int i = 1; i <= 4; ++i)
				fprintf(f_out, "%.6f    ", Tau(lambda, mu, n, N, i));
			fprintf(f_out, "\n");
		}
		fclose(f_out);
	}

	return EXIT_SUCCESS;
}
