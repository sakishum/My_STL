EXEC = test
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h*)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -std=c++11 -g -L/usr/local/Cellar/boost/1.54.0/lib -lpthread -lboost_system -lboost_filesystem-mt -lboost_thread-mt $(OBJECTS) -o $(EXEC)
 
%.o: %.cpp $(HEADERS)
	$(CXX) -std=c++11 -g -I/usr/local/Cellar/boost/1.54.0/include -c $< -o $@
 
.PHONY: clean
clean:
	$(RM) $(EXEC) $(OBJECTS) *.o
