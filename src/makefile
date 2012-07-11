
.SUFFIXES: .cpp .o


CC = clang++

OBJ = main.o FTPClient.o FTPConnection.o
INC =
DYLIB = -lboost_system -lboost_regex 
CFLAGS = -stdlib=libc++  -g
%.o: %.cpp
	$(CC) $(INC) $(CFLAGS) -c $<
all: cli test 

cli: $(OBJ)
	$(CC) $(OBJ) $(DYLIB) $(CFLAGS) -o cli

test: 
	make -C tests

main.o: FTPExceptions.hpp
FTPClient.o: FTPClient.hpp FTPConnection.hpp
FTPConection.o: FTPConnection.hpp

clean:
	rm -f tests/*.o *.o core
