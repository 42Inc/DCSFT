#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

#define N 11
int c1 = 1.0, c2 = 2.0, c3 = 3.0;
int C[N][N];
int Iter = 1253901;
float E = 0.01;

void getMatrix() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if 	(i >= j)
				C[i][j] = abs(j * c1 + (i - j) * c2);
			if 	(i < j)
				C[i][j] = abs((i * c2) + ((j - i) * c3));
			printf("%d\t",C[i][j]);
		}
		printf("\n");
	}
}

double funcMinId(double arr[N]) {
int min = arr[0];
int count = 0;
	for (int b = 0; b < N; b++)
		if(min > arr[b]){
			min = arr[b];
			count = b;
		}

	return count;
}

double funcMaxId(double arr[N]) {
float max = arr[0];
int count = 0;
	for (int b = 0; b < N; b++)
	{
		if(max < arr[b]){
			max = arr[b];
			count = b;
		}
	}
	return count;
}

int main(int argc, char const *argv[]) {
  getMatrix();

  double K[N],H[N],X[N],Y[N];
  double V = 0;
  double vMax = 0;
  double vMin = 0;
  int i = 0, l = 0, j = 0;
  double x[N],y[N];

  for (int iterI = 0; iterI < N; ++iterI) {
    K[iterI] = 0;
    H[iterI] = 0;
    x[iterI] = 0;
    y[iterI] = 0;
  }

  while (1) {
    j = funcMinId(K);
    i = funcMaxId(H);

    x[j] = x[j] + 1;
    y[i] = y[i] + 1;

    if (l > 0) {
      vMin = K[j] / l;
      vMax = H[i] / l;
      V = vMax - vMin;
      if (V < 0)
        V = V*(-1);
      if (V < E)
        break;
    }
    for (int k = 0; k < N; ++k) {
      K[k] = K[k] + C[i][k];
      H[k] = H[k] + C[k][j];
    }
    ++l;
  }

  for (int k = 0; k < N; ++k){
    X[k] = x[k] / l;
    Y[k] = y[k] / l;
  }

  for (int z = 0; z < N; ++z)
    printf("dispatcher = (%.2f) Center = (%.2f)\n",X[z],Y[z]);

  printf("V = %f\tl = %d\n",V/2,l);

  return EXIT_SUCCESS;
}
