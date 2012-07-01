//boost asio socket wrapper
#pragma once


#include <array>
#include <string>
#include <boost/asio.hpp>

#define BUF_SIZE 1024

using boost::asio::ip::tcp;

class FTPConnection{

	typedef std::array<char, BUF_SIZE> Buffer;
	
	public:
		void connect(const std::string &hostname, const std::string &port);
		void readFromSocketIntoBuffer(Buffer &buffer);
		size_t writeToSocketFromBuffer(Buffer &buffer, size_t amountToWrite);
		FTPConnection() : socket(ios){}

	private:
		boost::asio::io_service ios;
		tcp::socket socket;
};
