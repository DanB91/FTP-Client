#pragma once

#include <string>
#include <string.h>

#include "FTPConnection.hpp"
#include "FTPExceptions.hpp"



class FTPClient{


	public:
		std::string &getResponse(){ return this->lastResponseFromControlConnection; }
		void connect(const std::string &hostname, const std::string &port);
		void login(const std::string &username = "anonymous", const std::string &password = "");
		void printWorkingDirectory();


	private:
		std::string lastResponseFromControlConnection;
		FTPConnection controlConnection;

	        void sendAndReceiveCommands(std::string commandAndArgument, const std::string &expectedFTPCode );

};
