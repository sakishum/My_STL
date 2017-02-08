SOURCE := main.cpp
EXECUTE := test
CXX := g++-4.7
CXXFLAG := -std=c++11 -Wall 

all: $(SOURCE)
	$(CXX) $(CXXFLAG) -o $(EXECUTE) $?

.PHONY:clean
clean: $(EXECUTE)
	$(RM) $?
