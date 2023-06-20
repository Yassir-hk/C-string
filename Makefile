CFLAGS = -Wall

all: out

out: main.o
	@echo "Creation of the executable file"
	gcc $(CFLAGS) main.o -o out

main.o: main.c
	@echo "Compiling the source file"
	gcc $(CFLAGS) -c main.c

clean:
	@echo "Removing executable file and .o file"
	rm main.o out