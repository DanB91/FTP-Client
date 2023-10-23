//boost asio socket wrapper
#pragma once
#pragma clang diagnostic ignored "-Wparentheses"

#include <vector>
#include <string>
#include <sys/time.h> // fix for Boost error "declaration of 'select' must be imported from module 'Darwin.POSIX.sys.time' before it is required" on iOS
#include <boost/asio.hpp>
#include <array>
#include <fstream>

using boost::asio::ip::tcp;

class FTPConnection{
 
    
    public:
		void connect(const std::string &hostname, const std::string &port);
		std::string readLine(); //reads a /r/n terminated line from the socket
        std::vector<std::string> readLines();
		void writeLine(const std::string &buffer);
        void downloadFile(const std::string &dstPath);
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
