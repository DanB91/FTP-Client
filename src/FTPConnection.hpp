//boost asio socket wrapper
#pragma once
#pragma clang diagnostic ignored "-Wparentheses"

#include <vector>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class FTPConnection{

	typedef std::vector<char> Buffer;
	
	public:
		void connect(const std::string &hostname, const std::string &port);
		std::string readLine(); //reads a /r/n terminated line from the socket
		void writeLine(const std::string &buffer); 

		void close(){
			this->socket.close();
		}
		FTPConnection() : socket(ios){}
		~FTPConnection(){
			this->close();
		}

	private:
		boost::asio::io_service ios;
		tcp::socket socket;
};
