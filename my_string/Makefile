SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
EXC = test
CXXFLAG = -std=c++11 -Wall

all:$(EXC)

$(EXC):$(OBJ)
	$(CXX) $(CXXFLAG) $? -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

.PHONY:clean
clean:
	@echo clean...
	$(RM) $(OBJ) $(EXC)
