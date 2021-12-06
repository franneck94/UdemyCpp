DEBUG_FLAGS = -g3 -ggdb3 -O0
RELEASE_FLAGS = -DNDEBUG -O3
WARNING_FLAGS = -Wall -Wpedantic -Wshadow
SANITIZER_FLAGS = -fsanitize=address

FLAGS = $(DEBUG_FLAGS) $(WARNING_FLAGS) $(SANITIZER_FLAGS)

build:
	gcc $(FLAGS) Main.c -o Main

run:
	env ASAN_OPTIONS="detect_leaks=1" ./Main
