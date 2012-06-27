
.SUFFIXES: .cpp .o


CC = g++-mp-4.7



OBJ = main.o 
INC = /opt/local/include
DYLIB = /opt/local/lib

CFLAGS = -g -Wall -I$(INC) -L$(DYLIB) -lboost_regex


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
all: cli 

cli: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o cli

main.o: FTPExceptions.hpp

clean:
	rm -f *.o core
