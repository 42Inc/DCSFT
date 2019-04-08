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

  TT.cores = atoi(argv[3]);
  TT.time = 0;
  TT.occupancy = 0;
  TT.curr_core = 0;

  int tasks_amount = 0;

  int *list_of_tasks[2];
  list_of_tasks[0] = (int*)malloc(RANGE * sizeof(int));
  list_of_tasks[1] = (int*)malloc(RANGE * sizeof(int));

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
    printf("%s[SYSTEM]%s  For %s%d%s tasks from %s%s%s and %s%d%s EM has been applied %s%s%s method...%s\n", YELLOW, WHITE, GREEN, tasks_amount, WHITE, GREEN, filename, WHITE, GREEN, TT.cores, WHITE, GREEN, TDSP_method, WHITE, RESET);
    NFDH(list_of_tasks, tasks_amount);
  } else if (strcmp(TDSP_method, "FFDH") == 0) {
    printf("%s[SYSTEM]%s  For %s%d%s tasks from %s%s%s and %s%d%s EM has been applied %s%s%s method...%s\n", YELLOW, WHITE, GREEN, tasks_amount, WHITE, GREEN, filename, WHITE, GREEN, TT.cores, WHITE, GREEN, TDSP_method, WHITE, RESET);
    FFDH(list_of_tasks, tasks_amount);
  } else {
    fprintf(stderr, "%s[ERROR]%s  Unknown method for use!%s\n", RED, YELLOW, RESET);
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
