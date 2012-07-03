
.SUFFIXES: .cpp .o


CC = g++



OBJ = test.o ../FTPConnection.o
INC = /opt/local/include:/opt/local/include/cppunit
DYLIB = /opt/local/lib

CFLAGS = -g -Wall -I$(INC) -L$(DYLIB)  -lboost_system -lboost_regex -lcppunit -std=gnu++11 


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
all: test

test: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o test

test.o: FTPConnectionTest.hpp

clean:
	rm -f *.o core
