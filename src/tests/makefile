
.SUFFIXES: .cpp .o


CC = clang++-mp-3.1



OBJ = test.o ../FTPConnection.o ../FTPClient.o
INC = /opt/local/include -I/opt/local/include/cppunit
DYLIB = /opt/local/lib -lboost_system -lboost_regex  -lcppunit  
CFLAGS = -g -ggdb -Wall -I$(INC)   
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
all: test

test: $(OBJ)
	$(CC) $(OBJ) -L$(DYLIB) $(CFLAGS) -o test

test.o: FTPConnectionTest.hpp FTPClientTest.hpp

clean:
	rm -f *.o  core
