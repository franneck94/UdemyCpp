###############
## VARIABLES ##
###############
COMPILATION_MODE ?= Debug
ENABLE_WARNINGS ?= 1
WARNINGS_AS_ERRORS ?= 0
CPP_COMPILER ?= g++ # g++, clang++
CPP_STANDARD ?= c++2a # c++11, c++14, c++17, c++2a
EXECUTABLE_NAME ?= main

ifeq ($(COMPILATION_MODE), Debug)
CPP_COMPILER_FLAGS = -g -std=$(CPP_STANDARD) # -fopenmp
else ifeq ($(COMPILATION_MODE), Release)
CPP_COMPILER_FLAGS = -O3 -std=$(CPP_STANDARD) # -fopenmp
endif

ifeq ($(ENABLE_WARNINGS), 1)
CPP_COMPILER_FLAGS += -Wall -Wextra -Wpedantic
endif

ifeq ($(WARNINGS_AS_ERRORS), 1)
CPP_COMPILER_FLAGS += -Werror
endif

CPP_COMPILER_CALL = $(CPP_COMPILER) $(CPP_COMPILER_FLAGS)

CPP_SRCS = $(wildcard *.cpp)
CPP_OBJECTS = $(patsubst %.cpp, %.o, $(CPP_SRCS))

CC_SRCS = $(wildcard *.cc)
CC_OBJECTS = $(patsubst %.cc, %.o, $(CC_SRCS))

####################
## PSEUDO TARGETS ##
####################
build: $(EXECUTABLE_NAME)

#############
## TARGETS ##
#############
build_single:
	$(CPP_COMPILER_CALL) -o $(EXECUTABLE_NAME) $(FILE_NAME)

$(EXECUTABLE_NAME): $(CPP_OBJECTS) $(CC_OBJECTS)
	$(CPP_COMPILER_CALL) $^ -o $@

execute:
	./$(EXECUTABLE_NAME)

clean:
	$(RM) *.o

##############
## PATTERNS ##
##############
%.o : %.cpp
	$(CPP_COMPILER_CALL) -c $< -o $@

%.o : %.cc
	$(CPP_COMPILER_CALL) -c $< -o $@
