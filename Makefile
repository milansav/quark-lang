

all : build

build : main.o dynarr.o lexer.o parser.o debug.o keywords.o cstring.o
	gcc main.o dynarr.o lexer.o parser.o debug.o keywords.o cstring.o -o quark.out

remake : clear clean build

main.o : main.c
	gcc -c main.c

dynarr.o : ./dynarr/dynarr.c 
	gcc -c ./dynarr/dynarr.c 

lexer.o : ./lexer/lexer.c 
	gcc -c ./lexer/lexer.c 

parser.o : ./parser/parser.c 
	gcc -c ./parser/parser.c

debug.o : ./utils/debug.c
	gcc -c ./utils/debug.c

keywords.o : ./utils/keywords.c
	gcc -c ./utils/keywords.c

cstring.o : ./utils/cstring.c
	gcc -c ./utils/cstring.c

clean:
	if test -f "*.o"; then rm *.o; fi
	if test -f "quark.out"; then rm quark.out; fi

clear:
	clear
