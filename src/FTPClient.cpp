#include "FTPClient.hpp"
#include "FTPCodes.hpp"

void sendCommandToControlConnection(FTPConnection &controlConnection, std::string commandAndArguments)
{
	if(commandAndArguments.find("\r\n") == std::string::npos)
		commandAndArguments += "\r\n";

	controlConnection.writeLine(commandAndArguments);
}

std::string receiveAndVerifyResponseFromControlConnection(FTPConnection &controlConnection)
{
	std::string serverResponse = controlConnection.readLine();

	//special case if server needs to disconnect
	if(serverResponse.find(FTPCodes::CLOSING_CMD) == 0)
		throw FTPException(serverResponse);

	return serverResponse;

}

/*
 * Sends an FTP command to the control connection and receives a response from the server.
 * If that response doesn't reflect the expectedFTPCode, it throws an NonFatalUnexpectedFTPCodeException.
 * If the control socket needs to disconnect, it will throw an FTPConnection
 * Saves the connection response to the lastResponse
 */
void FTPClient::sendAndReceiveCommands(std::string commandAndArguments)
{
	
	sendCommandToControlConnection(this->controlConnection, commandAndArguments);
    
	this->lastResponseFromControlConnection = receiveAndVerifyResponseFromControlConnection(this->controlConnection);

}

//connects the control connection
void FTPClient::connect(const std::string &hostname, const std::string &port)
{
	this->controlConnection.connect(hostname, port);
	this->lastResponseFromControlConnection = receiveAndVerifyResponseFromControlConnection(this->controlConnection);

}

void FTPClient::login(const std::string &username, const std::string &password)
{
	this->sendAndReceiveCommands("USER " + username);
	this->sendAndReceiveCommands("PASS " + password);
}

void FTPClient::printWorkingDirectory()
{
	this->sendAndReceiveCommands("PWD");
}

void FTPClient::changeDirectory(const std::string &path)
{
    std::string command = "CWD";

    //if there is a supplied argument, put it in
    if(path.size() > 0)
        command += " " + path;

    this->sendAndReceiveCommands(command);
}

std::string FTPClient::listDirectory(const std::string &path)
{
    return "";

}

