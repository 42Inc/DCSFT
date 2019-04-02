#include "../include/extralib.h"

void NFDH(int **input_arr, int length, int n_machines) {
  countingSort(input_arr, length);
}

void FFDH() {

}

void countingSort(int **input_arr, int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d\t", input_arr[0][i]);
    printf("%d\n", input_arr[1][i]);
  }
}

void binaryHear() {

}
