all: utils.o
	gcc main.c -o main.exe

utils.o: lista_processo.o
	gcc -c ./utils/utils.c -o utils.o

lista_processo.o: lista_processo.h
	gcc -c ./tads/lista_processos/lista_processo.c -o list_processo.o

lista_processo.h: processo.o
	gcc -E ./tads/lista_processos/lista_processo.h -o lista_processo.h


processo.o: processo.h
	gcc -c ./tads/processo/processo.c -o processo.o

processo.h:
	gcc -E ./tads/processo/processo.h -o processo.h

clean:
	del *.o *exe

run:
	./main.exe