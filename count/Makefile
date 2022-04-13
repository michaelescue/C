wCC=x86_64-w64-mingw32-gcc
CC=gcc

default:
	"clean, all"

all:
	make count.exe

obj: 
	$(CC) -c $^ -o $@ -g

count.o: count.c
	$(CC) -c $^ -o $@ -g

count.exe: count.o
	$(CC) -o $@ $^ -g
	
clean:
	rm  *.o
	rm  *.exe
