DEBUG_FLAGS = -g3 -O0
RELEASE_FLAGS = -DNDEBUG -O3

FLAGS = $(RELEASE_FLAGS)

preprocess:
	gcc $(FLAGS) -E IfStatement.c > Temp.c

assemble:
	gcc $(FLAGS) -S IfStatement.c

compile:
	gcc $(FLAGS) -c IfStatement.c -o IfStatement.o

build:
	gcc $(FLAGS) IfStatement.o -o IfStatement

print_exe:
	objdump -CS IfStatement
