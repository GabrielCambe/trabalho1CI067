DEPENDENCIAS = strings_obj estacionamento_obj main_obj
OBJETOS = main.o estacionamento.o strings.o
main: $(DEPENDENCIAS)
	gcc $(OBJETOS)
main_obj: main.c
	gcc -c main.c
estacionamento_obj: estacionamento.c
	gcc -c estacionamento.c
strings_obj: strings.c
	gcc -c strings.c

cleant:
	rm *~
cleano:
	rm *.o
purge:
	rm a.out
