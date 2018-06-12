# Comandos do sistema operacional
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
DAT_DIR=./data

# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug doc

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: graphsEmpiricalAnalisys
debug: CFLAGS += -g -O0
debug: graphsEmpiricalAnalisys

# Alvo (target) para a construcao do executavel
# Define os arquivos Main.o Calculates.o Dijkstra.o Pair.o Graph.o como alvos
graphsEmpiricalAnalisys: $(OBJ_DIR)/Main.o $(OBJ_DIR)/Calculates.o $(OBJ_DIR)/Dijkstra.o $(OBJ_DIR)/BellmanFord.o $(OBJ_DIR)/ManageArchive.o $(OBJ_DIR)/Graph.o $(OBJ_DIR)/Pair.o
	@echo " ================================="
	@echo "    Ligando o alvo $@"
	@echo " ================================="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo " +++ [Executavel '$@' criado em $(BIN_DIR)] +++"
	@echo " ================================="

# Alvo (target) para a construcao do objeto Main.o
# Define os arquivos Main.cpp Calculates.cpp como dependencias.
$(OBJ_DIR)/Main.o: $(SRC_DIR)/Main.cpp $(SRC_DIR)/Calculates.cpp $(INC_DIR)/Calculates.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto Calculates.o
# Define os arquivos Calculates.cpp Dijkstra.cpp BellmanFord.cpp ManageArchive.cpp Graph.cpp Calculates.h Dijkstra.h BellmanFord.h ManageArchive.h Graph.h como dependencias.
$(OBJ_DIR)/Calculates.o: $(SRC_DIR)/Calculates.cpp $(SRC_DIR)/Dijkstra.cpp $(SRC_DIR)/BellmanFord.cpp $(SRC_DIR)/ManageArchive.cpp $(SRC_DIR)/Graph.cpp $(INC_DIR)/Calculates.h $(INC_DIR)/Dijkstra.h $(INC_DIR)/BellmanFord.h $(INC_DIR)/ManageArchive.h $(INC_DIR)/Graph.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto Dijkstra.o
# Define os arquivos Dijkstra.cpp Graph.cpp Pair.cpp Dijkstra.h Graph.h Pair.h como dependencias.
$(OBJ_DIR)/Dijkstra.o: $(SRC_DIR)/Dijkstra.cpp $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Pair.cpp $(INC_DIR)/Dijkstra.h $(INC_DIR)/Graph.h $(INC_DIR)/Pair.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto BellmanFord.o
# Define os arquivos BellmanFord.cpp Graph.cpp Pair.cpp BellmanFord.h Graph.h Pair.h como dependencias.
$(OBJ_DIR)/BellmanFord.o: $(SRC_DIR)/BellmanFord.cpp $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Pair.cpp $(INC_DIR)/BellmanFord.h $(INC_DIR)/Graph.h $(INC_DIR)/Pair.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto ManageArchive.o
# Define os arquivos ManageArchive.cpp Graph.cpp ManageArchive.h Graph.h como dependencias.
$(OBJ_DIR)/ManageArchive.o: $(SRC_DIR)/ManageArchive.cpp $(SRC_DIR)/Graph.cpp $(INC_DIR)/ManageArchive.h $(INC_DIR)/Graph.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto Graph.o
# Define os arquivos Graph.cpp Graph.h como dependencias.
$(OBJ_DIR)/Graph.o: $(SRC_DIR)/Graph.cpp $(INC_DIR)/Graph.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto Pair.o
# Define os arquivos Pair.cpp Pair.h como dependencias.
$(OBJ_DIR)/Pair.o: $(SRC_DIR)/Pair.cpp $(INC_DIR)/Pair.h
	$(CC) -c $(CFLAGS) -o $@ $<

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
