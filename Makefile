CC=gcc
SRC=main
DEPS=

default:
	@echo ""
	@echo "******* MAKEFILE *********"
	@echo "Directory: $(CURDIR)"
	@echo "Compiler: gcc"
	@echo "Targets: clean, all"
	@echo "******* MAKEFILE *********"
	@echo ""
	
all: $(SRC).o $(SRC).c
	make default
	make $(SRC).exe

$(SRC).o: $(SRC).c 
	$(CC) -c $^ -o $@ 

$(SRC).exe: $(SRC).o
	$(CC) -o $@ $^
	
clean:
	@echo "Cleaning..."
	rm $(SRC).o
	rm $(SRC).exe
