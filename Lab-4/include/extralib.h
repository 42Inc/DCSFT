#ifndef EXTRALIB_H
#define EXTRALIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../include/color.h"

#define RANGE 32
#define MAX_VALUE 255

struct timetable {
  int time;
  int cores;
  int occupancy;
  int curr_core;
} TT;

void NFDH(int **input_arr, int length);
void FFDH();
void countingSort(int **input_arr, int length);
void binaryHear();
void printList(int **input_arr, int length);
void tasksCheck(int **input_arr, int* length);

#endif
