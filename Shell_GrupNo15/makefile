all: compile run

compile:
	gcc -I ./include/ -o ./lib/command.o -c ./src/command.c	
	gcc -I ./include/ -o ./lib/prompt.o -c ./src/prompt.c
	gcc -I ./include/ -o ./bin/main ./lib/command.o ./lib/prompt.o ./src/main.c
	
run:
	./bin/main