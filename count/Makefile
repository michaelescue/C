wCC=x86_64-w64-mingw32-gcc
CC=gcc

default:
	echo "clean, all"

all: server.c

objonly: 
	$(CC) -c $^ -o $@

server.o: server.c
	$(CC) -c $^ -o $@ 

server.exe: server.o
	$(CC) -o $@ $^
	
clean:
	rm server.o
	rm server.exe
