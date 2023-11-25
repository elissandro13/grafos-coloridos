CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/vertice.o  $(OBJ)/main.o $(OBJ)/ordenacao.o $(OBJ)/heap.o $(OBJ)/aresta.o
HDRS = $(INC)/vertice.hpp $(INC)/ordenacao.hpp $(INC)/heap.hpp $(INC)/aresta.hpp
CFLAGS = -Wall -c -g -I$(INC)

EXE = $(BIN)/main

 
.PHONY: all debug clean 

all: $(BIN)/tp2.out

debug: $(BIN)/tp2_teste.out
	

#colocar -pg para debugar

$(BIN)/tp2_teste.out: $(OBJS)
	$(CC) -o $(BIN)/tp2_teste.out $(OBJS) $(LIBS)

$(BIN)/tp2.out: $(OBJS)
	$(CC) -o $(BIN)/tp2.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/vertice.o: $(HDRS) $(SRC)/vertice.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/vertice.o $(SRC)/vertice.cpp

$(OBJ)/ordenacao.o: $(HDRS) $(SRC)/ordenacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ordenacao.o $(SRC)/ordenacao.cpp

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.cpp

$(OBJ)/aresta.o: $(HDRS) $(SRC)/aresta.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/aresta.o $(SRC)/aresta.cpp	

	
clean:
	rm -f $(BIN)/*.out $(EXE) $(OBJS) gmon.out
