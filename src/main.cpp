#include <iostream>
#include <boost/lexical_cast.hpp>
#include "FTPExceptions.hpp"


#define HOSTNAME 1
#define PORT 2
#define MAX_ARGS 3
#define MIN_ARGS 2

void mainLoop(char *hostname, char *portStr)
{
	try{
		int port = boost::lexical_cast<int>(portStr);
	}
	catch(boost::bad_lexical_cast &){
		throw FTPException("Port must be a number!");
	}
}


int main(int argc, char **argv)
{
	try{

	//check for correct args
	if(argc < MIN_ARGS || argc > MAX_ARGS)
		std::cout << "Usage cli hostname [port]" << std::endl;
	else
		mainLoop(argv[HOSTNAME], argv[PORT]);
	
	}
	catch(FTPException &e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
