# @author Onurcan Erşen

CC = g++
CFLAGS = -Wall -Werror
EXE = ./bin/queueApp
BIN = ./bin
OBJ = ./obj
SRC = ./src
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm $(BIN)/* $(OBJ)/*

run:
	$(EXE)
