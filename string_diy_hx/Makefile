CXX = g++-4.8
ifeq (${MAKECMDGOALS}, debug)
	dir = debug
	cflag = -g -DDEBUG
else
	dir = release
	cflag = -O2 -DNDEBUG
	lflag = -s
endif
CXXFLAG = -std=c++11 -Wall -fexceptions $(cflag)

module = asio_client
target = ${dir}/${module}
sources = ${shell ls *.cpp}
objects = ${patsubst %.cpp,${dir}/%.o,${sources}}
deps = ${patsubst %.o,%.d,${objects}}
${shell mkdir -p ${dir}} 

#all:
	#@echo  $(target)

debug release: $(target)
-include ${deps}
$(target):$(objects)
	@echo "aaaa"
	$(CXX) -o ${target} ${objects} ${lflag} -pthread -lboost_system-mt -lboost_thread-mt
${objects} : ${dir}/%.o : %.cpp
	 $(CXX) ${CXXFLAG} -E -MMD -MT '${subst .cpp,.o,${dir}/$<}' -MF ${subst .cpp,.d,${dir}/$<} $< 1>/dev/null
	 $(CXX) ${CXXFLAG} -c $< -o $@

.PHONY: clean
clean: 
	$(RM) -r debug release
