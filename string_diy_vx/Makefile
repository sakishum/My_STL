SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
EXC = test
CXXFLAG = -Wall

all:$(EXC)

$(EXC):$(OBJ)
	$(CXX) $(CXXFLAG) $? -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

.PHONY:clean
clean:
	$(RM) $(EXC) $(OBJ)
