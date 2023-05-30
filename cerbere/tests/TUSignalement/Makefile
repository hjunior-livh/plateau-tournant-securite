CC=g++
FLAGS= -Wall
DEFS = ./defs
LIB = ./lib
SRC = ./src
INCLUDE	= ./include
BIN = ./bin

all: $(LIB)/Signalement.o 
	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $(SRC)/tuSignalement.cpp $(LIB)/Signalement.o 
	@echo "Compilation terminée"


$(LIB)/Signalement.o : $(SRC)/Signalement.cpp $(INCLUDE)/Signalement.h
	@echo "Compilation classe Signalement"
	$(CC) -c $(SRC)/Signalement.cpp -std=c++14 -o $@ $(FLAGS) -lpthread


