//boost asio socket wrapper
#pragma once


#include <vector>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class FTPConnection{

	typedef std::vector<char> Buffer;
	
	public:
		void connect(const std::string &hostname, const std::string &port);
		std::string readLineFromSocket();
		void writeLine(std::string &buffer);
		FTPConnection() : socket(ios){}

	private:
		boost::asio::io_service ios;
		tcp::socket socket;
};
