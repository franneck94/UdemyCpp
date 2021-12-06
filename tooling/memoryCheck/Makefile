DEBUG_FLAGS = -g3 -ggdb3 -O0
RELEASE_FLAGS = -DNDEBUG -O3
WARNING_FLAGS = -Wall -Wpedantic -Wshadow

FLAGS = $(DEBUG_FLAGS) $(WARNING_FLAGS)

build:
	gcc $(FLAGS) Main.c -o Main

check:
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--log-file=log.txt \
		./Main
