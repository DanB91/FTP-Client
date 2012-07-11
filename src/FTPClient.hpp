#pragma once

#include <string>

#include "FTPConnection.hpp"
#include "FTPExceptions.hpp"



class FTPClient{

    

	public:
		const std::string& getResponse() const { return this->lastResponseFromControlConnection; }
		void connect(const std::string &hostname, const std::string &port);
		void login(const std::string &username = "anonymous", const std::string &password = "");
		void printWorkingDirectory();
        void changeDirectory(const std::string &path = "");
        std::string listDirectory(const std::string &path = "");
        

	private:
		std::string lastResponseFromControlConnection;
		FTPConnection controlConnection;
        FTPConnection dataConnection;

	    void sendAndReceiveCommands(std::string commandAndArgument);

};
