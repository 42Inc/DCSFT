#ifndef EXTRALIB_H
#define EXTRALIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Delta(int x);
ulong Fact(int x);
double P(int j, double mu, double lambda, int N);
double U(double mu, int t, int N, int m, int l, int i);
double Pi(int t, double lambda, int r, int i);
double Q(int i, int n, int t, int m, int N, double mu, double lambda);
double R(int n, int t, int m, int N, double mu, double lambda);
double R_(int n, int N, double mu, double lambda, int t);
double Q_(int n, int N, int m, double mu, double lambda, int t);
double S(int n, int m, double mu, double lambda);

#endif
