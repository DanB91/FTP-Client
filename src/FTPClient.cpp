#include "FTPClient.hpp"
#include "FTPCodes.hpp"

void sendCommandToControlConnection(FTPConnection &controlConnection, std::string commandAndArguments)
{
	if(commandAndArguments.find("\r\n") == std::string::npos)
		commandAndArguments += "\r\n";

	controlConnection.writeLine(commandAndArguments);
}

std::string receiveAndVerifyResponseFromControlConnection(FTPConnection &controlConnection, const std::string &expectedFTPCode)
{
	std::string serverResponse = controlConnection.readLine();

	//check to see if it is the right ftp code
	if(serverResponse.find(expectedFTPCode) != 0)
		throw NonFatalUnexpectedFTPCodeException(serverResponse);

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
void FTPClient::sendAndReceiveCommands(std::string commandAndArguments, const std::string &expectedFTPCode )
{
	
	sendCommandToControlConnection(this->controlConnection, commandAndArguments);
	this->lastResponseFromControlConnection = receiveAndVerifyResponseFromControlConnection(this->controlConnection, expectedFTPCode);

}

//connects the control connection
void FTPClient::connect(const std::string &hostname, const std::string &port)
{
	this->controlConnection.connect(hostname, port);
	this->lastResponseFromControlConnection = receiveAndVerifyResponseFromControlConnection(this->controlConnection, FTPCodes::RDY_FOR_LOGIN);

}

void FTPClient::login(const std::string &username, const std::string &password)
{
	this->sendAndReceiveCommands("USER " + username, FTPCodes::USR_GOOD);
	this->sendAndReceiveCommands("PASS " + password, FTPCodes::LOGGEDIN);
}

void FTPClient::printWorkingDirectory()
{
	this->sendAndReceiveCommands("PWD", FTPCodes::PWD);
}

