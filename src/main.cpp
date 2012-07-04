#pragma clang diagnostic ignored "-Wparentheses"
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>
#include "FTPExceptions.hpp"
#include "FTPClient.hpp"


#define HOSTNAME 1
#define PORT 2
#define MAX_ARGS 3
#define MIN_ARGS 2



void verifyValidHostnameAndPort(const std::string &hostname, const std::string &portStr)
{
	try{
		boost::lexical_cast<int>(portStr);
	}catch(boost::bad_lexical_cast &){
		throw FTPException("Port must be a number!");
	}

	boost::regex r("[A-Za-z0-9\\-\\.]+");
	
	if(!boost::regex_match(hostname, r))
			throw FTPException("Hostname is invalid!");
}


void mainLoop(const std::string &hostname, const std::string &portStr = "21")
{
	verifyValidHostnameAndPort(hostname, portStr);
	
	FTPClient ftp;
	ftp.connect(hostname, portStr);

}

int main(int argc, char **argv)
{

	try{
		if(argc == MIN_ARGS) 
			mainLoop(argv[HOSTNAME]);
		else if(argc == MAX_ARGS) 
			mainLoop(argv[HOSTNAME], argv[PORT]);
		else
			throw FTPException("Usage: cli hostname [port]");
	}
	catch(FTPException &e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
