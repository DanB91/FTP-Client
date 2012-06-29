#pragma once

#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class FTPClient{

	struct CommandResponse{
		int FTPCode;
		std::string response;
	};

	public:
		bool exited();
		CommandResponse getResponse();
		void connect(const std::string &hostname, const std::string &port);
		FTPClient() : ios(), commandSocket(ios) {}

	private:
		boost::asio::io_service ios;
		tcp::socket commandSocket;
		
};
