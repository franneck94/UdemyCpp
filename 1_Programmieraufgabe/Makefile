DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CPPFLAGS = -g3 -Wall -std=c++1z -U__STRICT_ANSI__
else
    CPPFLAGS = -O2 -Wall -std=c++1z -U__STRICT_ANSI__
endif

CPP = g++ $(CPPFLAGS)
SRCS = $(wildcard *.cc *.cpp) 
OBJECTS = $(patsubst %.cc %.cpp, %.o, $(SRCS))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CPP) -o $@ $^

%.o: %.c
	$(CPP) -c -o $@ $<