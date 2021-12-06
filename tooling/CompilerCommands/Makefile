DEBUG_FLAGS = -g3 -O0
RELEASE_FLAGS = -DNDEBUG -O3

FLAGS = $(RELEASE_FLAGS)

preprocess:
	g++ $(FLAGS) -E IfStatement.c > Temp.c

assemble:
	g++ $(FLAGS) -S IfStatement.c

compile:
	g++ $(FLAGS) -c IfStatement.c -o IfStatement.o

build:
	g++ $(FLAGS) IfStatement.o -o IfStatement

print_exe:
	objdump -CS IfStatement
