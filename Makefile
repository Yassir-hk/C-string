CFLAGS = -Wall

all: out

out: test.o
	@echo "Creation of the executable file"
	gcc $(CFLAGS) test.o -o out

test.o: test.c
	@echo "Compiling the source file"
	gcc $(CFLAGS) -c test.c

clean:
	@echo "Removing executable file and .o file"
	rm test.o out