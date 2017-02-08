CXX_FLAG = -O2 -Wall 
PRG = test
OBJ = main.o

$(PRG):$(OBJ)
	$(CXX) -o $@ $(OBJ)

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXX_FLAG) -c $*.cpp -o $*.o

.PRONY:clean
clean:
	@echo "Removing linked and compiled files..."
	$(RM) $(OBJ) $(PRG)
