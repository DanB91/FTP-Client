
.SUFFIXES: .cpp .o


CC = g++



OBJ = main.o FTPClient.o FTPConnection.o
INC = /opt/local/include
DYLIB = /opt/local/lib

CFLAGS = -g -Wall -I$(INC) -L$(DYLIB)  -lboost_system -lboost_regex  -std=gnu++11 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
all: cli test 

cli: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o cli

test: 
	make -C tests

main.o: FTPExceptions.hpp
FTPClient.o: FTPClient.hpp FTPConnection.hpp
FTPConection.o: FTPConnection.hpp

clean:
	rm -f *.o core
