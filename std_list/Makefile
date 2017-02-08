EXEC = main
SOURCES = $(wildcard *.cpp ./public/proto_files/*.cc ./player/*.c*)
HEADERS = $(wildcard *.h*)
TARGET = test
OBJECTS = $(SOURCES:.cpp=.o)
CXXFLAG := -std=c++11 -L/usr/local/Cellar/boost/1.58.0/lib -lboost_system-mt -lboost_regex-mt -lboost_filesystem-mt -lboost_thread-mt -ldl -lpthread\
	-lboost_program_options-mt -L/usr/local/lib\
	-lmysqlpp -lmysqlclient -I/include/json -ljsoncpp

#-ljsoncpp 

all: $(EXEC)
 
main: $(OBJECTS)
	$(CXX) $(CXXFLAG) $(OBJECTS) -o $(TARGET)
 
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAG) -c $< -o $@

check:
	valgrind --tool=memcheck --leak-check=yes --leak-check=full --dsymutil=yes ./main

init:
	ln -s /Users/sakishum1118/MyLua/gameLua_Test/.gitignore
	ln -s /Users/sakishum1118/MyBoost/asio_server/NetWorkPack.cpp
	ln -s /Users/sakishum1118/MyBoost/asio_server/NetWorkPack.h
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/NetworkServer.cpp
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/NetworkServer.h
	ln -s /Users/sakishum1118/MyLua/gameLua_Test/Tp_typedef.cpp
	ln -s /Users/sakishum1118/MyLua/gameLua_Test/Tp_typedef.h
	ln -s /Users/sakishum1118/MyBoost/asio_loginserver/application.cpp
	ln -s /Users/sakishum1118/MyBoost/asio_loginserver/application.h
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/connection.cpp
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/connection.h
	ln -s /Users/sakishum1118/MyBoost/muti_dbmodule/custom_parameters.cpp
	ln -s /Users/sakishum1118/MyBoost/muti_dbmodule/custom_parameters.h
	ln -s /Users/sakishum1118/MyBoost/muti_dbmodule/databaseInstance.cpp
	ln -s /Users/sakishum1118/MyBoost/muti_dbmodule/databaseInstance.h
	ln -s /Users/sakishum1118/MyBoost/memory_share/db_write.cpp
	ln -s /Users/sakishum1118/MyBoost/memory_share/db_write.h
	ln -s /Users/sakishum1118/MyBoost/asio_server/event_manager.h
	ln -s /Users/sakishum1118/MyBoost/asio_server/helper.cpp
	ln -s /Users/sakishum1118/MyBoost/asio_server/helper.h
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/io_service_pool.cpp
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/io_service_pool.h
	ln -s /Users/sakishum1118/MyCCpp/Key_word/keyword.cpp
	ln -s /Users/sakishum1118/MyCCpp/Key_word/keyword.h
	ln -s /Users/sakishum1118/MyServer/Glog/glog_Test/log_record.h
	ln -s /Users/sakishum1118/MyServer/Glog/glog_Test/liblog.a
	ln -s /Users/sakishum1118/MyBoost/muti_dbmodule/multithread_db.cpp
	ln -s /Users/sakishum1118/MyBoost/muti_dbmodule/multithread_db.h
	ln -s /Users/sakishum1118/MyBoost/asio_server/operate_config.cpp
	ln -s /Users/sakishum1118/MyBoost/asio_server/operate_config.h
	ln -s /Users/sakishum1118/MyBoost/asio_server/platform.h
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/server.cfg
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/server_data.h
	ln -s /Users/sakishum1118/MyBoost/asio_server/singleton_template.h
	ln -s /Users/sakishum1118/MyCCpp/Timer/timer_manager.cpp
	ln -s /Users/sakishum1118/MyCCpp/Timer/timer_manager.h
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/user_message.h
	ln -s /Users/sakishum1118/MyBoost/asio_gateserver/user_struct.h
	#cp -r /Users/sakishum1118/MyBoost/asio_accountserver/json .
 
.PHONY: clean
clean:
	$(RM) $(TARGET) *.o
