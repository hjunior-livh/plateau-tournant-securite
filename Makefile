CC=g++
FLAGS=-std=c++17 -lpthread
FLAGS2=-Wall 
DEFS = ./include
CPPGPIO = ./include/cppgpio
LIB = ./lib
SRC = ./src
BIN = ./bin

all: $(LIB)/HautParleur.o $(LIB)/Signalisation.o $(LIB)/Sauvegarde.o $(LIB)/Position.o $(LIB)/Signalement.o $(LIB)/Consigne.o $(LIB)/Journal.o  $(LIB)/Charge.o $(LIB)/Interrupteur.o $(LIB)/AlimentationBatterie.o $(LIB)/Ares.o $(LIB)/Moteur.o $(LIB)/Cerbere.o $(LIB)/C_courantMoteur.o $(LIB)/buttons.o $(LIB)/output.o $(LIB)/gpio.o $(LIB)/tools.o $(LIB)/ina219.o $(LIB)/PlateauTournant.o $(LIB)/Cube.o $(LIB)/C_Force.o $(LIB)/i2c.o $(LIB)/SignalCube.o
	@echo "Compilation programme principal"
	$(CC)  $(SRC)/tiPlateauTournant.cpp  $(LIB)/Ares.o $(LIB)/HautParleur.o $(LIB)/Signalisation.o $(LIB)/Sauvegarde.o $(LIB)/Position.o $(LIB)/PlateauTournant.o $(LIB)/Cube.o $(LIB)/Signalement.o $(LIB)/Consigne.o $(LIB)/Journal.o $(LIB)/Charge.o $(LIB)/Cerbere.o  $(LIB)/Interrupteur.o $(LIB)/AlimentationBatterie.o $(LIB)/Moteur.o $(LIB)/C_courantMoteur.o $(LIB)/C_Force.o $(LIB)/buttons.o $(LIB)/output.o $(LIB)/SignalCube.o $(LIB)/gpio.o $(LIB)/i2c.o $(LIB)/tools.o $(LIB)/ina219.o  -o $(BIN)/tiPlateauTournant $(FLAGS2) $(FLAGS) 
	@echo "Compilation success"

$(LIB)/HautParleur.o : $(SRC)/HautParleur.cpp $(DEFS)/HautParleur.h
	@echo "Compilation classe HautParleur"
	$(CC) -c $(SRC)/HautParleur.cpp  -o $@ $(FLAGS) 

$(LIB)/Signalisation.o : $(SRC)/Signalisation.cpp $(DEFS)/Signalisation.h 
	@echo "Compilation classes de Signalisation"
	$(CC) -c $(SRC)/Signalisation.cpp  -o $@ $(FLAGS) 	

$(LIB)/Sauvegarde.o : $(SRC)/Sauvegarde.cpp $(DEFS)/Sauvegarde.h
	@echo "Compilation classe Sauvegarde"
	$(CC) -c $(SRC)/Sauvegarde.cpp  -o $@ $(FLAGS) 

$(LIB)/Position.o : $(SRC)/Position.cpp $(DEFS)/Position.h
	@echo "Compilation classe Position"
	$(CC) -c $(SRC)/Position.cpp  -o $@ $(FLAGS) 

$(LIB)/Cube.o : $(SRC)/Cube.cpp $(DEFS)/Cube.h 
	@echo "Compilation classes de Cube"
	$(CC) -c $(SRC)/Cube.cpp  -o $@ $(FLAGS) 	

$(LIB)/Signalement.o : $(SRC)/Signalement.cpp $(DEFS)/Signalement.h
	@echo "Compilation classe Signalement"
	$(CC) -c $(SRC)/Signalement.cpp  -o $@ $(FLAGS)	

$(LIB)/Consigne.o : $(SRC)/Consigne.cpp $(DEFS)/Consigne.hpp 
	@echo "Compilation classes de Consigne"
	$(CC) -c $(SRC)/Consigne.cpp  -o $@ $(FLAGS) 	

$(LIB)/Journal.o : $(SRC)/Journal.cpp $(DEFS)/Journal.hpp
	@echo "Compilation classe Journal"
	$(CC) -c $(SRC)/Journal.cpp  -o $@ $(FLAGS)		

$(LIB)/ina219.o : $(SRC)/ina219.cc $(DEFS)/ina219.h
	@echo "Compilation classe ina219"
	$(CC) -c $(SRC)/ina219.cc   -o $@ $(FLAGS) 

$(LIB)/Interrupteur.o : $(SRC)/Interrupteur.cpp $(DEFS)/Interrupteur.h 
	@echo "Compilation classes de Interrupteur"
	$(CC) -c $(SRC)/Interrupteur.cpp  -o $@ $(FLAGS) 	

$(LIB)/Charge.o : $(SRC)/Charge.cpp $(DEFS)/Charge.hpp
	@echo "Compilation classe Charge"
	$(CC) -c $(SRC)/Charge.cpp  -o $@ $(FLAGS) 

$(LIB)/gpio.o : $(SRC)/gpio.cpp $(CPPGPIO)/gpio.hpp 
	@echo "Compilation classes de gpio"
	$(CC) -c $(SRC)/gpio.cpp  -o $@ $(FLAGS) 	

$(LIB)/tools.o : $(SRC)/tools.cpp $(DEFS)/tools.hpp 
	@echo "Compilation classes de tools"
	$(CC) -c $(SRC)/tools.cpp  -o $@ $(FLAGS) 	

$(LIB)/output.o : $(SRC)/output.cpp $(CPPGPIO)/output.hpp 
	@echo "Compilation classes de output"
	$(CC) -c $(SRC)/output.cpp  -o $@ $(FLAGS) 

$(LIB)/buttons.o : $(SRC)/buttons.cpp $(CPPGPIO)/buttons.hpp 
	@echo "Compilation classes de buttons"
	$(CC) -c $(SRC)/buttons.cpp  -o $@ $(FLAGS) 	

$(LIB)/AlimentationBatterie.o : $(SRC)/AlimentationBatterie.cpp $(DEFS)/AlimentationBatterie.h 
	@echo "Compilation classes de AlimentationBatterie"
	$(CC) -c $(SRC)/AlimentationBatterie.cpp -o $@ $(FLAGS) 	

$(LIB)/Ares.o : $(SRC)/Ares.cpp $(DEFS)/Ares.h 
	@echo "Compilation classes de Ares"
	$(CC) -c $(SRC)/Ares.cpp  -o $@ $(FLAGS)

$(LIB)/Moteur.o : $(SRC)/Moteur.cpp $(DEFS)/Moteur.h 
	@echo "Compilation classes de Moteur"
	$(CC) -c $(SRC)/Moteur.cpp  -o $@ $(FLAGS)	

$(LIB)/Cerbere.o : $(SRC)/Cerbere.cpp $(DEFS)/Cerbere.hpp 
	@echo "Compilation classes de Cerbere"
	$(CC) -c $(SRC)/Cerbere.cpp  -o $@ $(FLAGS)	

$(LIB)/PlateauTournant.o : $(SRC)/PlateauTournant.cpp $(DEFS)/PlateauTournant.h 
	@echo "Compilation classes de PlateauTournant"
	$(CC) -c $(SRC)/PlateauTournant.cpp  -o $@ $(FLAGS)		
	
$(LIB)/C_courantMoteur.o : $(SRC)/C_courantMoteur.cpp $(DEFS)/C_courantMoteur.hpp
	@echo "Compilation classes de C_courantMoteur"
	$(CC) -c $(SRC)/C_courantMoteur.cpp  -o $@ $(FLAGS)		

$(LIB)/C_Force.o : $(SRC)/C_Force.cpp $(DEFS)/C_Force.hpp
	@echo "Compilation classes de C_Force"
	$(CC) -c $(SRC)/C_Force.cpp  -o $@ $(FLAGS)	

$(LIB)/i2c.o : $(SRC)/i2c.cpp $(CPPGPIO)/i2c.hpp
	@echo "Compilation classes de i2c"
	$(CC) -c $(SRC)/i2c.cpp  -o $@ $(FLAGS)	

$(LIB)/SignalCube.o : $(SRC)/SignalCube.cpp $(DEFS)/SignalCube.hpp
	@echo "Compilation classes de SignalCube"
	$(CC) -c $(SRC)/SignalCube.cpp  -o $@ $(FLAGS)		