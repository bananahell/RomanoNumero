# Consts:
# IncludeDIR = *.hpp DIR
# CC = gcc or g++
# DB = gdb
# CFLAGS = comp line flags (-ansi = ansi law; -Wall, -Wextra = warnings; -I./ = *.h DIR)
# ObjDIR = *.o DIR
# LibDIR = lib DIR
# LibDIR -> enable when using, put $(LIBS) at end of gogo's command
LibDIR =./lib/ /home/user/gtest-1.7.0/include /home/user/gtest-1.7.0/lib/.libs/libgtest.a
IncludeDIR =./include/
CppDIR=./src/
ObjDIR=./src/obj/
CC=g++
DB=gdb
CFLAGS=-ansi -Wall -Wextra -I$(IncludeDIR) -pthread
LIBS=-lgtest

# Vars:
# -- ADAPT THIS IN YOUR PROGRAM --
headers = RomanoConversor.hpp
mainObject = RomanoConversorTeste
objects = RomanoConversor.o

# Set of *.hpp on which the *.cpp depend
_DEPS = $(headers)
DEPS = $(patsubst %,$(IncludeDIR)%,$(_DEPS))

# Set of *.o
_OBJ = $(mainObject).o $(objects)
OBJ = $(patsubst %,$(ObjDIR)%,$(_OBJ))

# Gathers *.o
$(ObjDIR)%.o: $(CppDIR)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

# Creates executable (Linux)
$(mainObject): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

# Gets the files and organize in the lib include src/obj structure
.PHONY: PrepareDIR
prepareDIR:
	mkdir -p $(LibDIR)
	mkdir -p $(IncludeDIR)
	mkdir -p $(CppDIR)
	mkdir -p $(ObjDIR)
	mv *.hpp $(IncludeDIR); true
	mv *.cpp $(CppDIR); true

# Call for execution
.PHONY: execute
execute:
	./$(mainObject)

# Call for debugging
.PHONY: debug
debug:
	$(DB) ./$(mainObject)

# Call for *.o clean up
.PHONY: clean
clean:
	rm $(ObjDIR)*.o

# Call for help with this makefile's commands
.PHONY: help
help:
	@echo "\n\t Makefile\n"
	@echo " make = compiles program"
	@echo " make prepareDIR = prepares project in the "lib include src/obj" structure (use this if all files are with this makefile)"
	@echo " make execute = executes succesfully compiled program"
	@echo " make debug = (gdb) debugs succesfully compiled program"
	@echo " make clean = removes objects from obj directory\n"
	@echo " For use with program, change variables -headers- and -objects- inside makefile\n\n"
