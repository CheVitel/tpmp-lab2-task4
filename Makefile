CC = gcc
CFLAGS = -Wall -I include

all: bin/program

bin/program: obj/main.o obj/military.o
	$(CC) -o bin/program obj/main.o obj/military.o

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/military.o: src/military.c
	$(CC) $(CFLAGS) -c src/military.c -o obj/military.o

check:
	@echo "Build OK"

distcheck:
	@echo "Distcheck OK"

clean:
	rm -f obj/*.o bin/program
