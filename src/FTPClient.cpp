
#include <regex>
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
const std::string& FTPClient::sendAndReceiveCommands(std::string commandAndArguments)
{
	sendCommandToControlConnection(this->controlConnection, commandAndArguments);
    
	this->lastResponseFromControlConnection = receiveAndVerifyResponseFromControlConnection(this->controlConnection);
    
    return this->getResponse();
}

//connects the control connection
const std::string& FTPClient::connect(const std::string &hostname, const std::string &port)
{
    this->controlConnection.connect(hostname, port);
    this->lastResponseFromControlConnection = receiveAndVerifyResponseFromControlConnection(this->controlConnection);
    return this->getResponse();
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

std::vector<std::string> FTPClient::listDirectory(const std::string &path)
{
    auto response = this->sendAndReceiveCommands("PASV");
    
    std::regex r("(\\d+),(\\d+),(\\d+),(\\d+),(\\d+),(\\d+)");
    std::smatch matches;
    std::vector<std::string> listing;
    
    if (std::regex_search(response, matches, r)) {
        std::string host = matches[1].str() + "." + matches[2].str() + "." + matches[3].str() + "." + matches[4].str();
        std::string port = std::to_string(std::stoi(matches[5].str()) * 256 + std::stoi(matches[6].str()));
        this->dataConnection.connect(host, port);
        response = this->sendAndReceiveCommands("LIST " + path);
        listing = this->dataConnection.readLines();
    } else {
        // TODO: error
    }
    
    return listing;
}

std::ofstream FTPClient::downloadFile(const std::string &fileName, const std::string &dstPath)
{
    auto response = this->sendAndReceiveCommands("TYPE I");
    response = this->sendAndReceiveCommands("PASV");
    
    std::regex r("(\\d+),(\\d+),(\\d+),(\\d+),(\\d+),(\\d+)");
    std::smatch matches;
    std::ofstream result;
    
    if (std::regex_search(response, matches, r)) {
        std::string host = matches[1].str() + "." + matches[2].str() + "." + matches[3].str() + "." + matches[4].str();
        std::string port = std::to_string(std::stoi(matches[5].str()) * 256 + std::stoi(matches[6].str()));
        this->dataConnection.connect(host, port);
        response = this->sendAndReceiveCommands("RETR " + fileName);
        this->dataConnection.downloadFile(dstPath);
        printf("");
    } else {
        // TODO: error
    }
    
    return result;
}

