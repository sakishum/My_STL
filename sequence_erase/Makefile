SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
CXX := g++
EXC := test
FLAG := -std=c++11 -Wall

all: $(EXC)

$(EXC): $(OBJ)
	$(CXX) $(FLAG) $? -o $@

%.o: %.cpp
	$(CXX) $(FLAG) -c $< -o $@

.PHONY:clean
clean: $(EXC) $(OBJ)
	$(RM) $?
