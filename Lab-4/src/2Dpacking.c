#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../include/extralib.h"
#include "../include/color.h"

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "%s[ERROR]%s  Not enough arguments!%s\n", RED, YELLOW, RESET);
    exit(EXIT_FAILURE);
  }

  char* filename = argv[1];
  char* TDSP_method = argv[2];
  int n = atoi(argv[3]);
  int tasks_amount = 0;
  int list_of_tasks[2][RANGE];

  FILE* fd_in = fopen(filename, "r");
  if (fd_in) {
    fscanf(fd_in, "%d", &tasks_amount);
    if (tasks_amount > RANGE) {
      fprintf(stderr, "%s[ERROR]%s  Amount of tasks is too large!%s\n", RED, YELLOW, RESET);
      fclose(fd_in);
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tasks_amount; ++i) {
      fscanf(fd_in, "%d", &list_of_tasks[0][i]);
      fscanf(fd_in, "%d", &list_of_tasks[1][i]);
    }

    fclose(fd_in);
  }

  if (strcmp(TDSP_method, "NFDH") == 0) {
    printf("%s[SYSTEM]%s  For tasks from %s%s%s and %s%d%s EM has been applied %s%s%s method...%s\n", YELLOW, WHITE, GREEN, filename, WHITE, GREEN, n, WHITE, GREEN, TDSP_method, WHITE, RESET);
    NFDH(list_of_tasks, tasks_amount, n);
  } else if (strcmp(TDSP_method, "FFDH") == 0) {
    printf("%s[SYSTEM]%s  For tasks from %s%s%s and %s%d%s EM has been applied %s%s%s method...%s\n", YELLOW, WHITE, GREEN, filename, WHITE, GREEN, n, WHITE, GREEN, TDSP_method, WHITE, RESET);
    FFDH(list_of_tasks, tasks_amount, n);
  } else {
    fprintf(stderr, "%s[ERROR]%s  Unknown method for use!%s\n", RED, YELLOW, RESET);
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
