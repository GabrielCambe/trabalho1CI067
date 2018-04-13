main: estacionamento main.o
	gcc estacionamento.o main.o
main.o: main.c
	gcc -c main.c
estacionamento: estacionamento.c
	gcc -c estacionamento.c

invoke: main
	./a.out

temp:
	rm *~
obj:
	rm *.o
purge:
	rm a.out
