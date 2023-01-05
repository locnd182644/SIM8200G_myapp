CC=gcc
CFLAGS=-I.
DEPS = mjson.h
OBJ = mjson.o testMjson.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	rm *.o