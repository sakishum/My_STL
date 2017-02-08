CXX = c++-4.8
CFLAG = -std=c++11 -lpthread -lprotobuf -lboost_system -lboost_filesystem-mt -lboost_thread-mt -lboost_regex-mt 

all: main.cpp
	$(CXX) $(CFLAG) -o test -Wall $?

.PHONY: clean
clean:
	@echo "Removing linked and compiled files ..."
	$(RM) test

