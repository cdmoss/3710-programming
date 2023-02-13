CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lglut -lGLU -lGL
SOURCES=as2.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=as2

all: $(SOURCES) $(EXECUTABLE) clean

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.d *.o 