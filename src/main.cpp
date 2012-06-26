#include <iostream>
#include "Utility.hpp"

#define HOSTNAME 1
#define PORT 2
#define MAX_ARGS 3
#define MIN_ARGS 2

void mainLoop(char *hostname, char *port)
{
	
}


int main(int argc, char **argv)
{
	//check for correct args
	if(argc < MIN_ARGS || argc > MAX_ARGS)
		std::cout << "Usage cli hostname [port]" << std::endl;
	else
		mainLoop(argv[HOSTNAME], argv[PORT]);


	return 0;
}
