all: func.o
	gcc main.c -o main

func.o: tad.h
	gcc -c func.c

clean:
	rm -rf *.o

run:
	./main