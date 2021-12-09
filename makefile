all: utils.o
	gcc main.c -o main

utils.o:
	gcc -c ./utils/utils.c -o utils.o

clean:
	del *.o *exe

run:
	./main