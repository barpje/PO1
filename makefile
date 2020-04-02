CXX = g++
CXXFLAGS = -Wall -g
SOURCES = $(wildcard *.cpp)
OBJS = $(SOURCES:.cpp=.o)
EXEC = exec

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<
clean:
	rm -rf *.o $(EXEC)

run:
	./$(EXEC)

valgrind: 
	valgrind --tool=memcheck ./$(EXEC)

.PHONY: all clean run valgrind
