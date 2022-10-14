CC=g++
CFLAGS=-I.
-std=gnu++11
DEPS = scanner.h testScanner.h token.h
OBJ = main.o scanner.o testScanner.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
scanner: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY: clean

clean:
	-rm *.o $(objects)