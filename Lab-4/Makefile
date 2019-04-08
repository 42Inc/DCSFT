CC = g++
QUIET = @
CFLAGS = -g3 -O0 -Wall
OFLAGS = -c -Wall
LIB = -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDES = -I $(SRC_DIR)
DIRS = $(BIN_DIR) $(OBJ_DIR) result
OBJ = $(OBJ_DIR)/rightonecodefile.o $(OBJ_DIR)/taskgenerator.o

.PHONY: all bins objs clean rebuild exec
all: bins

bins: $(DIRS) objs
	$(CC) $(OBJ_DIR)/rightonecodefile.o $(CFLAGS) -o $(BIN_DIR)/cmpl $(LIB)
	$(CC) $(OBJ_DIR)/taskgenerator.o $(CFLAGS) -o $(BIN_DIR)/taskgen $(LIB)

$(DIRS):
	$(QUIET)mkdir $(DIRS)

objs:
	$(CC) $(OFLAGS) $(SRC_DIR)/rightonecodefile.cpp -o $(OBJ_DIR)/rightonecodefile.o $(INCLUDES)
	$(CC) $(OFLAGS) $(SRC_DIR)/taskgenerator.cpp -o $(OBJ_DIR)/taskgenerator.o $(INCLUDES)

clean:
	$(QUIET)rm -rfv $(DIRS)

rebuild:
	make clean ; make

exec:
	make clean ; make ; ./run.sh ; ./mkgraph.sh
