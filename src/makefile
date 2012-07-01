
.SUFFIXES: .cpp .o


CC = g++



OBJ = main.o FTPClient.o FTPConnection.o
INC = /opt/local/include
DYLIB = /opt/local/lib

CFLAGS = -g -Wall -I$(INC) -L$(DYLIB) -ggdb -lboost_system -lboost_regex  -std=gnu++11 


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
all: cli 

cli: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o cli

main.o: FTPExceptions.hpp
FTPClient.o: FTPClient.hpp FTPConnection.hpp
FTPConection.o: FTPConnection.hpp

clean:
	rm -f *.o core
