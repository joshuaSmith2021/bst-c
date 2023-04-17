CC = gcc
CFLAGS = -ansi -pedantic -Werror -g
MAIN = bintree
OBJS = $(MAIN).o linkedqueue.o

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

bintree.o: bintree.c
	$(CC) -c $(CFLAGS) bintree.c

linkedqueue.o: linkedqueue.c
	$(CC) -c $(CFLAGS) linkedqueue.c

clean:
	rm -f $(OBJS)
