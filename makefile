CFLAGS= -c

all:	main	

main:  main.o model.o ticket.o
	gcc -o main main.o model.o ticket.o

main.o: main.c
	gcc $(CFLAGS) main.c

model.o: model/model.c model/model.h
	gcc $(CFLAGS) model/model.c

ticket.o: ticket/ticket.c ticket/ticket.h
	gcc $(CFLAGS) ticket/ticket.c

clean:
	rm -f main.o model.o ticket.o
