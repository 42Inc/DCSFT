CC = gcc
QUIET = @
CFLAGS = -g3 -O0 -Wall
OFLAGS = -c -Wall
LIB = -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDES = -I $(SRC_DIR)
DIRS = $(BIN_DIR) $(OBJ_DIR) result
OBJ = $(OBJ_DIR)/reliability.o $(OBJ_DIR)/extralib.o

.PHONY: all bins objs clean rebuild exec
all: bins

bins: $(DIRS) objs
	$(CC) $(OBJ) $(CFLAGS) -o $(BIN_DIR)/cmpl $(LIB)

$(DIRS):
	mkdir $(DIRS)

objs:
	$(CC) $(OFLAGS) $(SRC_DIR)/reliability.c -o $(OBJ_DIR)/reliability.o $(INCLUDES)
	$(CC) $(OFLAGS) $(SRC_DIR)/extralib.c -o $(OBJ_DIR)/extralib.o $(INCLUDES)

clean:
	$(QUIET)rm -rfv $(DIRS)

rebuild:
	make clean ; make

exec:
	make clean ; make ; ./$(BIN_DIR)/cmpl ; ./mkgraph.sh
