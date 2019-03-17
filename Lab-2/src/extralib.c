#include "../include/extralib.h"

ulong Fact(int x) {
  ulong fac = 1;
  for (uint i = 2; i <= x; i++)
    fac *= i;

  return fac;
}

double P(int j, double mu, double lambda, int N) {
  double sum = 0;
  for (int l = 0; l <= N; l++)
    sum += pow(mu / lambda, l) / Fact(l);
  sum = 1 / sum;
  sum *= pow(mu / lambda, j) / Fact(j);

  return sum;
}

int Delta(int x) {
  return (x >= 0) ? 1 : 0;
}

double U(double mu, int t, int N, int m, int l, int i) {
  double u = pow(mu * t, l) / Fact(l);
  u *= Delta(N - i - m) * pow(m, l) * exp(-m * mu * t) + Delta(m - N + i) * pow(N - i, l) * exp(-(N - i) * mu * t);

  return u;
}

double Pi(int t, double lambda, int r, int i) {
  return pow(i * lambda * t, r) / Fact(r) * exp(-i * lambda * t);
}

double Q(int i, int n, int t, int m, int N, double mu, double lambda) {
  double sum_u = 0;
  double sum_Pi = 0;
  double sum = 0;
  for (int l = 0; l < 1; l++) {
    sum_u = U(mu, t, N, m, l, i);
    for (int r = 0; r <= i - n + l; r++)
      sum_Pi += Pi(t, lambda, r, i);
    sum += sum_u * sum_Pi;
  }

  return sum;
}

double R(int n, int t, int m, int N, double mu, double lambda) {
  double sum = 0;
  for (int i = n; i <= N; i++)
    sum += P(i, mu, lambda, N) * Q(i, n, t, m, N, mu, lambda);

  return sum;
}

double R_(int n, int N, double mu, double lambda, int t) {
  double sum = 0;
  double sum2 = 0;
  for(int i = n; i <= N; i++)
  {
    sum += P(i, lambda, mu, N);
    sum2 = 0;
    for (int r = 0; r <= i - n; r++)
      sum2 += Pi(t, lambda, r, i);
    sum *= sum2;
  }

  return sum;
}

double Q_(int n, int N, int m, double mu, double lambda, int t) {
  double sum = 0;
  double sum2 = 0;
  for (int i = 0; i <= n - 1; i++)
  {
    sum += P(i, lambda, mu, N);
    sum2 = 0;
    for (int l = 0; l <= n - i - 1; l++)
      sum2 += U(mu, t, N, m, l, i);
    sum *= sum2;
  }

  return 1 - sum;
}

double S(int n, int m, double mu, double lambda) {
  double sum = 0;
  for (int j = 0; j <= n - 1; j++)
    sum += pow(m * mu / lambda, j) * exp(-m * mu / lambda) / Fact(j);

  return 1 - sum;
}
