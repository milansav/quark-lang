

all : build

build : main.o dynarr.o lexer.o parser.o
	gcc main.o dynarr.o lexer.o parser.o -o build

main.o : main.c
	gcc -c main.c

dynarr.o : ./dynarr/dynarr.c 
	gcc -c ./dynarr/dynarr.c 

lexer.o : ./lexer/lexer.c 
	gcc -c ./lexer/lexer.c 

parser.o : ./parser/parser.c 
	gcc -c ./parser/parser.c

clean:
	rm *.o
	rm build
