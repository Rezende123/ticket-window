CFLAGS= -c

all:	main	

main:  objects/main.o objects/model.o objects/ticket.o
	gcc -o main objects/main.o objects/model.o objects/ticket.o

objects/main.o: main.c
	gcc $(CFLAGS) main.c

objects/model.o: model/model.c model/model.h
	gcc $(CFLAGS) model/model.c

objects/ticket.o: ticket/ticket.c ticket/ticket.h
	gcc $(CFLAGS) ticket/ticket.c

clean:
	rm -f objects/main.o objects/model.o objects/ticket.o
