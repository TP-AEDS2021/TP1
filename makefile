all: lista_processo.o
	gcc main.c -o main.exe

lista_processo.o: lista_processo.h
	gcc -c list_processo.c -o list_processo.o

lista_processo.h: utils.o
	gcc -E ./tads/lista_processos/lista_processo.h -o lista_processo.h

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