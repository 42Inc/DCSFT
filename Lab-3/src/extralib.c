#include "../include/extralib.h"

double Theta(double lambda, double mu, int n, int N, int m) {
	double totalSum = 0.0f;
	double totalMul = 1.0f;
	for (int j = n + 1; j <= N; ++j) {
		double mul = (j - 1 >= N - m && j - 1 <= N) ? (N - (j - 1)) * mu : m * mu;
		totalMul *= mul / ((j - 1) * lambda);

		totalSum += totalMul / (j * lambda);
	}

	return totalSum + 1 / (n * lambda);
}

double Tau(double lambda, double mu, int n, int N, int m) {
	if (n == 1)
    return m * mu;

	double totalMul = 1.0f;
	for (int l = 1; l <= n - 1; ++l)
		totalMul *= l * lambda / (mu * l);

	double totalSum = 0.0f;
	for (int j = 1; j <= n - 1; ++j) {
		double totalMul = 1.0f;
		for (int l = j; l <= n - 1; ++l) {
			double mul = (l >= N - m && l <= N) ? (N - l) * mu : m * mu;
			totalMul *= l * lambda / mul;
		}
		totalSum += totalMul / (j * lambda);
	}

	return totalMul + totalSum;
}
