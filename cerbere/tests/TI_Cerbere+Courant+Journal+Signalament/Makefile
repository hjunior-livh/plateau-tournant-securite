CC=g++
FLAGS= -Wall
DEFS = ./defs
LIB = ./lib
SRC = ./src
INCLUDE	= ./include
BIN = ./bin

all: $(LIB)/ina219.o $(LIB)/C_CourantMoteur.o $(LIB)/Cerbere.o $(LIB)/Consigne.o $(LIB)/Journal.o $(LIB)/Signalement.o 
	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $(SRC)/main.cpp $(LIB)/ina219.o $(LIB)/C_CourantMoteur.o $(LIB)/Cerbere.o $(LIB)/Consigne.o $(LIB)/Journal.o $(LIB)/Signalement.o -std=c++17 -std=c++17 -lpthread -o $(BIN)/tiCerbereCourantJournalSignalement 
	@echo "Compilation terminée"


$(LIB)/ina219.o : $(SRC)/ina219.cc $(INCLUDE)/ina219.h
	@echo "Compilation classe ina129"
	$(CC) -c $(SRC)/ina219.cc -std=c++14 -o $@ $(FLAGS) -lpthread

$(LIB)/C_CourantMoteur.o : $(SRC)/C_courantMoteur.cpp $(INCLUDE)/C_courantMoteur.hpp
	@echo "Compilation classe C_courantMoteur"
	$(CC) -c $(SRC)/C_courantMoteur.cpp -std=c++17 -o $@ $(FLAGS) -lpthread

$(LIB)/Cerbere.o : $(SRC)/Cerbere.cpp $(INCLUDE)/Cerbere.hpp
	@echo "Compilation classe Cerbere"
	$(CC) -c $(SRC)/Cerbere.cpp -std=c++17 -o $@ $(FLAGS) -lpthread

$(LIB)/Consigne.o : $(SRC)/Consigne.cpp $(INCLUDE)/Consigne.hpp
	@echo "Compilation classe Consigne"
	$(CC) -c $(SRC)/Consigne.cpp -std=c++17 -o $@ $(FLAGS) -lpthread


$(LIB)/Signalement.o: $(SRC)/Signalement.cpp $(INCLUDE)/Signalement.h
	@echo "Compilation classe Signalement "
	$(CC) -c $(SRC)/Signalement.cpp -std=c++17 -o $@ $(FLAGS) -lpthread

$(LIB)/Journal.o: $(SRC)/Journal.cpp $(INCLUDE)/Journal.hpp
	@echo "Compilation classe Journal "
	$(CC) -c $(SRC)/Journal.cpp -std=c++17 -o $@ $(FLAGS) -lpthread
