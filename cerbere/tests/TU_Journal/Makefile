CC=g++
FLAGS= -Wall
DEFS = ./defs
LIB = ./lib
SRC = ./src
INCLUDE	= ./include
BIN = ./bin

all: $(LIB)/Journal.o 
	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $(SRC)/main.cpp  $(LIB)/Journal.o 
	@echo "Compilation terminée"


$(LIB)/Journal.o : $(SRC)/Journal.cpp $(INCLUDE)/Journal.hpp
	@echo "Compilation classe Journal"
	$(CC) -c $(SRC)/Journal.cpp -std=c++14 -o $@ $(FLAGS) -lpthread
