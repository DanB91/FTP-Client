#include "FTPClient.hpp"
#include "FTPExceptions.hpp"

void FTPClient::connect(const std::string &hostname, const std::string &port)
{
	try{
		//resolves host name
		tcp::resolver resolver(this->ios);
		tcp::resolver::query query(hostname, port);
		auto iterator = resolver.resolve(query);

		//connects to host
		boost::asio::connect(this->commandSocket, iterator);
	}
	catch(boost::system::system_error &){
		throw FTPException("Error connecting to host");
	}
}
