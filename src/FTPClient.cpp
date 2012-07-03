#include "FTPClient.hpp"
#include "FTPExceptions.hpp"

void FTPClient::connect(const std::string &hostname, const std::string &port)
{
   this->commandConnection.connect(hostname, port);


}
