#pragma once

#include <string>


class FTPClient{

	struct CommandResponse{
		int FTPCode;
		std::string response;
	};

	public:
		bool exited();
		CommandResponse getResponse();
		void connect(const std::string &hostname, int port);

	private:
		


};
