SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
EXC = test
CXXFLSG = -Wall

all:$(EXC)

$(EXC):$(OBJ)
	$(CXX) $(CXXFLSG) $? -o $@

%.o:%.cpp
	$(CXX) $(CXXFLSG) -c $< -o $@

.PHONY:clean
clean:
	$(RM) $(EXC) $(OBJ)
