main: src/code.c src/cnvtorom.c
	gcc -ansi -pedantic -Wall -Werror -I include/ src/code.c src/cnvtorom.c -o main