SOURCE := main.cpp
CXXFLAG := -Wall -O2 -std=c++11
EXECUTE := test

all: $(SOURCE)
	$(CXX) -o $(EXECUTE) $(CXXFLAG) $?

.PHONY: clean
clean: $(EXECUTE)
	$(RM) $? *.o
