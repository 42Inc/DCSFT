#include "../include/extralib.h"

/*
  input_arr[2][RANGE], where input_arr[0][i] - time & input_arr[1][i] - core
  That's important...
    ^
  T |
  I |
  M |
  E |__ __ __ __>
      C O R E
*/

void NFDH(int **input_arr, int length) {
  countingSort(input_arr, length);
  tasksCheck(input_arr, &length);

  printf("%s[NFDH]%s  Initializing first layer...%s\n", GREEN, WHITE, RESET);
  for (int i = length - 1; i >= 0; --i) {
    if ((input_arr[0][i] != 0) && (input_arr[0][i] != 0)) {
      if ((TT.curr_core + input_arr[1][i]) <= TT.cores) {
        TT.curr_core += input_arr[1][i];
        if (TT.occupancy < input_arr[0][i])
          TT.occupancy = input_arr[0][i];

        int j = i - 1;
        while ((TT.curr_core + input_arr[1][j]) <= TT.cores) {
          printf("Curr stat: %d - %d\n", TT.occupancy, TT.curr_core);
          if (TT.curr_core < TT.cores) {
            TT.curr_core += input_arr[1][j];
            if (TT.occupancy < input_arr[0][j]) {
              TT.occupancy = input_arr[0][j];
            }
            input_arr[0][j] = 0;
            input_arr[1][j] = 0;
            --j;
          }
        }
      } else {
        printf("%s[NFDH]%s  Initializing next layer...%s\n", GREEN, WHITE, RESET);
        TT.occupancy += input_arr[0][i];
        TT.curr_core = input_arr[1][i];
      }
      printf("Curr stat: %d - %d\n", TT.occupancy, TT.curr_core);
    }
  }
  printf("%s[NFDH]%s  Occupancy: %s%d%s\n", GREEN, WHITE, GREEN, TT.occupancy, RESET);
}

void FFDH() {
//     int currentLevel = 0, nextLevel = 0, freeMachineNumber = 0, myLevels[m];
//   	tasks *ptr = root;
//
//   	currentLevel = 0;
//   	freeMachineNumber = ptr->rank;
//   	ptr->start_time = currentLevel;
//   	nextLevel = ptr->time;
//
//   	ptr = ptr->next;
//   	while (ptr->next != NULL)
//   	{
//   		if (ptr->rank + freeMachineNumber > n)
//   		{
//   			currentLevel = nextLevel;
//   			nextLevel += ptr->time;
//   			ptr->start_time = currentLevel;
//   			freeMachineNumber = ptr->rank;
//   		} else {
//   			ptr->start_time = currentLevel;
//   			freeMachineNumber += ptr->rank;
//   		}
//   		ptr = ptr->next;
//   	}
//
//   	return nextLevel;
}

void countingSort(int **input_arr, int length) {
	int output_arr[2][length];
	int freq[MAX_VALUE];
	memset(freq, 0, sizeof(freq));

	for (int i = 0; i < length; ++i)
		freq[input_arr[0][i]]++;

	int total = 0;
	for (int i = 0; i < MAX_VALUE; ++i) {
		int oldCount = freq[i];
		freq[i] = total;
		total += oldCount;
	}

	for (int i = 0; i < length; ++i) {
		output_arr[0][freq[input_arr[0][i]]] = input_arr[0][i];
    output_arr[1][freq[input_arr[0][i]]] = input_arr[1][i];
		freq[input_arr[0][i]]++;
	}

	for (int i = 0; i < length; ++i) {
		input_arr[0][i] = output_arr[0][i];
    input_arr[1][i] = output_arr[1][i];
  }
}

void binaryHear() {

}

void printList(int **input_arr, int length) {
    for (int i = length - 1; i > 0; --i)
      printf("%d - %d\n", input_arr[0][i], input_arr[1][i]);
}

void tasksCheck(int **input_arr, int* length) {
  int newLength = *length;
  for (int i = *length - 1; i > 0; --i) {
    if (input_arr[1][i] > TT.cores) {
      printf("%s[SYSTEM]%s  Requested %s%d%s cores, while max cores is %s%d%s... %sDrop out!%s\n", YELLOW, WHITE, RED, input_arr[1][i], WHITE, GREEN, TT.cores, WHITE,YELLOW, RESET);
      input_arr[0][i] = 0;
      input_arr[1][i] = 0;
      --newLength;
    }
  }
  *length = newLength;
}
