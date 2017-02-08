SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
EXC = test
CXXFLAG = -Wall -std=c++11

all:$(EXC)

$(EXC):$(OBJ)
	$(CXX) $(CXXFLAG) $? -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $? -o $@

.PHONY:clean
clean:
	$(RM) $(OBJ) $(EXC)

