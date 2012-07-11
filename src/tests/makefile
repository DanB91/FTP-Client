
.SUFFIXES: .cpp .o


CC = clang++


OBJ = test.o ../FTPConnection.o ../FTPClient.o
INC = -I/opt/local/include
DYLIB =-lboost_system -lboost_regex 
CFLAGS = -g -Wall -stdlib=libc++
 
%.o: %.cpp
	$(CC) $(INC) $(CFLAGS) -c $<
all: test

test: $(OBJ)
	$(CC) $(OBJ) $(DYLIB) $(CFLAGS) -o test

test.o:
clean:
	rm -f *.o  core
