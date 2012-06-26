
.SUFFIXES: .cpp .o


CC =clang++ 


CFLAGS = -g -Wall

OBJ = main.o 
INC = /opt/local/include

%.o: %.cpp
	$(CC) $(CFLAGS) -I $(INC) -c $<
all: cli 

cli: $(OBJ)
	$(CC) $(OBJ) -o cli

main.o: Utility.hpp

clean:
	rm -f *.o core
