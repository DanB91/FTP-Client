#pragma once

#include <string>
#include <sys/time.h>

#include "FTPConnection.hpp"


class FTPClient{

	public:
    
		const std::string& getResponse() const { return this->lastResponseFromControlConnection; }
		const std::string& connect(const std::string &hostname, const std::string &port);
		void login(const std::string &username = "anonymous", const std::string &password = "");
		void printWorkingDirectory();
        void changeDirectory(const std::string &path = "");
        std::vector<std::string> listDirectory(const std::string &path = "");
        std::ofstream downloadFile(const std::string &fileName, const std::string &dstPath);
    
	private:
    
		std::string lastResponseFromControlConnection;
		FTPConnection controlConnection;
        FTPConnection dataConnection;

	    const std::string& sendAndReceiveCommands(std::string commandAndArgument);

};
