
.SUFFIXES: .cpp .o


CC = g++-mp-4.7



OBJ = main.o FTPClient.o
INC = /opt/local/include
DYLIB = /opt/local/lib

CFLAGS = -g -Wall -I$(INC) -L$(DYLIB) -ggdb -lboost_system -lboost_regex  -std=gnu++11 


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
all: cli 

cli: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o cli

main.o: FTPExceptions.hpp
FTPClient.o: FTPClient.hpp

clean:
	rm -f *.o core
