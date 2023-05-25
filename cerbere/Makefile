CC=g++
FLAGS= -Wall
DEFS = ./defs
LIB = ./lib
SRC = ./src
INCLUDE	= ./include
BIN = ./bin

all: $(LIB)/ina219.o $(LIB)/C_CourantMoteur.o $(LIB)/Consigne.o $(LIB)/Cerbere.o
	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $/testCourant.cpp $(LIB)/ina219.o $(LIB)/C_CourantMoteur.o $(LIB)/Cerbere.o $(LIB)/Consigne.o
	@echo "Compilation terminée"

#Partie des classes statique de la partie de BPLA

$(LIB)/ina219.o : $(SRC)/ina219.cc $(INCLUDE)/ina219.h
	@echo "Compilation classe ina129"
	$(CC) -c $(SRC)/ina219.cc -std=c++14 -o $@ $(FLAGS) -lpthread

$(LIB)/C_CourantMoteur.o : $(SRC)/C_courantMoteur.cpp $(INCLUDE)/C_courantMoteur.hpp
	@echo "Compilation classe C_courantMoteur"
	$(CC) -c $(SRC)/C_courantMoteur.cpp -std=c++14 -o $@ $(FLAGS) -lpthread

$(LIB)/Cerbere.o : $(SRC)/Cerbere.cpp $(INCLUDE)/Cerbere.hpp
	@echo "Compilation classe Cerbere"
	$(CC) -c $(SRC)/Cerbere.cpp -std=c++14 -o $@ $(FLAGS) -lpthread

$(LIB)/Consigne.o : $(SRC)/Consigne.cpp $(INCLUDE)/Consigne.hpp
	@echo "Compilation classe Consigne"
	$(CC) -c $(SRC)/Consigne.cpp -std=c++14 -o $@ $(FLAGS) -lpthread

#Partie des classes statique de la partie de WHAMET