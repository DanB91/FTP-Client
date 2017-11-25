#include "FTPConnection.hpp"
#include "FTPExceptions.hpp"

void FTPConnection::connect(const std::string &hostname, const std::string &port)
{	
	try{
		//resolves host name
		tcp::resolver resolver(this->ios);
		tcp::resolver::query query(hostname, port);

		//connects to host
		boost::asio::connect(this->socket, resolver.resolve(query));
	}
	catch(boost::system::system_error &){
		throw FTPException("Error connecting to host");
	}
}

//reads '\r\n' terminated line in
std::string FTPConnection::readLine()
{

	std::string retStr;
	boost::asio::streambuf responseBuffer;

	try{
		boost::asio::read_until(this->socket, responseBuffer, "\r\n");
		std::istream responseStream(&responseBuffer);
		std::getline(responseStream, retStr);
	}
	catch(boost::system::system_error &){
		throw FTPException("Error reading line");
	}
	return retStr;
}

void FTPConnection::writeLine(const std::string &buffer)
{
	boost::asio::streambuf b;
	std::ostream os(&b);
	os << buffer;
	try{
		boost::asio::write(this->socket, b);
	}catch(boost::system::system_error &){
		throw FTPException("Error writing line");
	}

}

void FTPConnection::downloadFile(const std::string &dstPath)
{
    boost::system::error_code error;
    boost::asio::streambuf responseBuffer;
    std::ofstream outFile(dstPath.c_str(), std::ofstream::out | std::ofstream::binary);
    
    boost::asio::read(this->socket, responseBuffer, boost::asio::transfer_all(), error);
    outFile << &responseBuffer;

    if (error && error != boost::asio::error::eof) {
        throw FTPException(std::string("Error getting file: ") + error.message());
    }
}




