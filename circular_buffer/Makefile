EXEC = main
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h*)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC)

main: $(OBJECTS)
	$(CXX) -L/usr/local/Cellar/boost/1.54.0/lib -lpthread -lboost_system -lboost_filesystem-mt -lboost_thread-mt $(OBJECTS) -o $(EXEC)
 
%.o: %.cpp $(HEADERS)
	$(CXX) -I/usr/local/Cellar/boost/1.54.0/include -c $< -o $@
 
.PHONY: clean
clean:
	$(RM) $(EXEC) $(OBJECTS) *.o
