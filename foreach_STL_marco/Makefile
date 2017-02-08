SOURCE := main.cpp
CXX := g++-4.7
CXXFLAG := -std=c++11 -Wall -g
EXECUTE := test
all: $(SOURCE)
	$(CXX) $(CXXFLAG) -o $(EXECUTE) $?

.PHONY: clean
clean: $(EXECUTE)
	$(RM) $?
