#ifndef COLORLIB_H
#define COLORLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>

#include "../include/color.h"

#define RESET   "\033[0m"
#define WHITE     "\033[1;97m"
#define YELLOW  "\033[1;93m"
#define GREEN   "\033[1;92m"
#define RED     "\033[1;91m"

#define SUCCESS   "\033[1;92m [SUCCESS]\t\033[0m"
#define ERROR     "\033[1;91m [ERROR]\t\033[0m"
#define SYSTEM    "\033[1;93m [SYSTEM]\t\033[0m"

#endif
