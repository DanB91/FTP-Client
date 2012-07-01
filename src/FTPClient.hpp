#pragma once

#include <string>
#include "FTPConnection.hpp"


class FTPClient{

	struct CommandResponse{
		int FTPCode;
		std::string response;
	};

	public:
		bool exited();
		CommandResponse getResponse();
		void connect(const std::string &hostname, const std::string &port);


	private:
		CommandResponse lastResponse;
		FTPConnection commandConnection;
};
