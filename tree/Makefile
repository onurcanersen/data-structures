# @author Onurcan Erşen

CC = g++
CFLAGS = -Wall -Werror
EXE = ./bin/tree
BIN = ./bin
OBJ = ./build
SRC = ./src
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BIN)/* $(OBJ)/*

run:
	$(EXE)