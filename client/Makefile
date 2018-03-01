OBJECTS = sockets_cl

CC = gcc
CFLAGS = -Wall

$(OBJECTS):$(OBJECTS).o error_handing.o get_num.o
	$(CC) $(OBJECTS).o error_handing.o get_num.o -o $(OBJECTS)
$(OBJECTS).o:$(OBJECTS).c
	$(CC) $(CFLAGS) -c $(OBJECTS).c -o $(OBJECTS).o
error_handing.o:error_handing.c
	$(CC) $(CFLAGS) -c error_handing.c -o error_handing.o
get_num.o:get_num.c
	$(CC) $(CFLAGS) -c get_num.c -o get_num.o

.PHONY:clean
clean:
	@rm *.o sockets_cl
