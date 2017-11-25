#pragma once

#include <string>

#include "FTPConnection.hpp"
#include "FTPExceptions.hpp"



class FTPClient{

    private:
    
    enum class ConnectionMode
    {
        Control, Data
    };

	public:
    
		const std::string& getResponse() const { return this->lastResponseFromControlConnection; }
		const std::string& connect(const std::string &hostname, const std::string &port);
		void login(const std::string &username = "anonymous", const std::string &password = "");
		void printWorkingDirectory();
        void changeDirectory(const std::string &path = "");
        std::string listDirectory(const std::string &path = "");
        std::ofstream downloadFile(const std::string &fileName, const std::string &dstPath);
    
	private:
    
		std::string lastResponseFromControlConnection;
		FTPConnection controlConnection;
        FTPConnection dataConnection;

	    const std::string& sendAndReceiveCommands(std::string commandAndArgument);

};
