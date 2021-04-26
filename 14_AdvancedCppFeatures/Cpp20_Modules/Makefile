CPP_COMPILER := clang++-10
CPP_FLAGS := -std=c++2a -fmodules-ts -Wall -Wconversion -Wpedantic
EXE_NAME := main

all: build

build:
	$(CPP_COMPILER) $(CPP_FLAGS) --precompile adder.cppm -o adder.pcm
	$(CPP_COMPILER) $(CPP_FLAGS) -c adder.pcm -o adder.o
	$(CPP_COMPILER) $(CPP_FLAGS) -fprebuilt-module-path=. adder.o main.cpp -o $(EXE_NAME)

execute:
	./$(EXE_NAME)
