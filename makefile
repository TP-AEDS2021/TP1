all: utils.o
	gcc main.c -o main.exe

utils.o: processo.c
	gcc -c ./utils/utils.c -o utils.o

processo.c: processo.h
	gcc -c ./tads/processo/processo.c -o processo.o

processo.h:
	gcc -E ./tads/processo/processo.h -o processo.h

clean:
	del *.o *exe

run:
	./main.exe