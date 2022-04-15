CC=gcc
SRC=main
DEPS=

default:
	@echo ""
	@echo "******* MAKEFILE *********"
	@echo "Directory: $(CURDIR)"
	@echo "Compiler: gcc"
	@echo "Targets: clean, all"
	@echo "Default: all"
	@echo "******* MAKEFILE *********"
	@echo ""
	
all: $(SRC).o $(SRC).c
	@echo "Make-ing $@..."	
	make $(SRC).exe

$(SRC).o: $(SRC).c
	@echo "Make-ing $@..."		
	$(CC) -c $^ -o $@ 

$(SRC).exe: $(SRC).o
	@echo "Make-ing $@..."
	$(CC) -o $@ $^
	
clean:
	@echo "Make-ing $@..."
	rm $(SRC).o
	rm $(SRC).exe

run: 
	make clean
	make all
	@echo "Make-ing $@..."
	@echo "Running $(SRC).exe:\n"
	./$(SRC).exe