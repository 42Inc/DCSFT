#include "../include/extralib.h"

void NFDH(int **input_arr, int length, int n_machines) {
  countingSort(input_arr, length);
}

void FFDH() {

}

void countingSort(int **input_arr, int length) {
	int output_arr[2][length];
	int freq[MAX_VALUE];
	memset(freq, 0, sizeof(freq));

	for (int i = 0; i < length; i++)
		freq[input_arr[0][i]]++;

	int total = 0;
	for (int i = 0; i < MAX_VALUE; i++) {
		int oldCount = freq[i];
		freq[i] = total;
		total += oldCount;
	}

	for (int i = 0; i < length; i++) {
		output_arr[0][freq[input_arr[0][i]]] = input_arr[0][i];
    output_arr[1][freq[input_arr[0][i]]] = input_arr[1][i];
		freq[input_arr[0][i]]++;
	}

	for (int i = 0; i < length; i++) {
		input_arr[0][i] = output_arr[0][i];
    input_arr[1][i] = output_arr[1][i];
  }
}

void binaryHear() {

}
