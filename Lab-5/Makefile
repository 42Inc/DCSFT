CC = gcc
CP = g++
QUIET = @
CFLAGS = -g3 -O0 -Wall
OFLAGS = -c -Wall
LIB = -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDES = -I $(SRC_DIR)
DIRS = $(BIN_DIR) $(OBJ_DIR) result
OBJ = $(OBJ_DIR)/dispatcher_tester.o

.PHONY: all bins objs clean rebuild exec
all: bins

bins: $(DIRS) objs
	$(CP) $(OBJ_DIR)/dispatcher_main.o $(CFLAGS) -o $(BIN_DIR)/cmpl_main $(LIB)
	$(CC) $(OBJ_DIR)/dispatcher_tester.o $(CFLAGS) -o $(BIN_DIR)/cmpl_test $(LIB)

$(DIRS):
	$(QUIET)mkdir $(DIRS)

objs:
	$(CC) $(OFLAGS) $(SRC_DIR)/dispatcher_tester.c -o $(OBJ_DIR)/dispatcher_tester.o $(INCLUDES)
	$(CP) $(OFLAGS) $(SRC_DIR)/dispatcher_main.cpp -o $(OBJ_DIR)/dispatcher_main.o $(INCLUDES)

clean:
	$(QUIET)rm -rfv $(DIRS)

rebuild:
	make clean ; make

exec:
	make clean ; make ; ./bin/cmpl ; ./mkgraph.sh
