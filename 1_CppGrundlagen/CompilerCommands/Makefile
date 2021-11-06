DEBUG_FLAGS = -g3 -O0
RELEASE_FLAGS = -DNDEBUG -O3

FLAGS = $(RELEASE_FLAGS)

preprocess:
	g++ $(FLAGS) -E Functions2.cc > Temp.cc

assemble:
	g++ $(FLAGS) -S Functions2.cc

compile:
	g++ $(FLAGS) -c Functions2.cc -o Functions2.o

build:
	g++ $(FLAGS) Functions2.o -o Functions2

print_exe:
	objdump -CS Functions2
