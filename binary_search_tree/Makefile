CC = g++
CFLAGS = -Wall -Werror
EXE = ./bin/binary_search_tree
SRC = ./src
OBJ = ./build
BIN = ./bin
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ)/* $(BIN)/*

run:
	$(EXE)