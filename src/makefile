
.SUFFIXES: .cpp .o


CC = clang++-mp-3.1



OBJ = main.o FTPClient.o FTPConnection.o
INC = /opt/local/include
DYLIB = /opt/local/lib -lboost_system -lboost_regex
CFLAGS = -g  -I$(INC) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
all: cli test 

cli: $(OBJ)
	$(CC) $(OBJ) -L$(DYLIB) $(CFLAGS) -o cli

test: 
	make -C tests

main.o: FTPExceptions.hpp
FTPClient.o: FTPClient.hpp FTPConnection.hpp
FTPConection.o: FTPConnection.hpp

clean:
	rm -f tests/*.o *.o core
