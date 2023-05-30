CC=g++
FLAGS= -Wall
DEFS = ./defs
LIB = ./lib
SRC = ./src
INCLUDE	= ./include
BIN = ./bin

all: $(LIB)/ina219.o $(LIB)/C_CourantMoteur.o
	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $(SRC)/ProgPrincipal.cpp $(LIB)/ina219.o $(LIB)/C_CourantMoteur.o
	@echo "Compilation terminée"


$(LIB)/ina219.o : $(SRC)/ina219.cc $(INCLUDE)/ina219.h
	@echo "Compilation classe ina129"
	$(CC) -c $(SRC)/ina219.cc -std=c++14 -o $@ $(FLAGS) -lpthread

$(LIB)/C_CourantMoteur.o : $(SRC)/C_courantMoteur.cpp $(INCLUDE)/C_courantMoteur.hpp
	@echo "Compilation classe C_courantMoteur"
	$(CC) -c $(SRC)/C_courantMoteur.cpp -std=c++14 -o $@ $(FLAGS) -lpthread
