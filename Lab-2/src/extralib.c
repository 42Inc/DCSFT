#include "../include/extralib.h"

int rejection_func() {
  return;
}

int recovery_func() {
  return;
}

int probability(int i) {
  double P = 2;
  return P;
}

int conditional_probability(int i) {
  double Q = 2;
  return Q;
}

int reliability_func(int n, int N) {
  double R = 0, P = 0, Q = 0;

  for (int i = n; i < N; ++i) {
    P = probability(i);
    Q = conditional_probability(i);
    R += P * Q;
  }
  return R;
}
