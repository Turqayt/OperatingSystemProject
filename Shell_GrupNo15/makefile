CC		:= gcc
C_FLAGS := -w
BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lpthread

EXECUTABLE	:= shell

all: $(BIN)/$(EXECUTABLE)
	
clean:
	-$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	[ -d ./$(BIN) ] || mkdir -p ./$(BIN)
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
