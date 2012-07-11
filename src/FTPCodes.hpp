/*
 * This file contains all the possible FTP codes wrapped in a class 
 */

#pragma once
#include <string>

namespace FTPCodes{

	const std::string RDY_FOR_LOGIN = "220"; //ready for login
	const std::string USR_GOOD = "331"; //user is good, input password
	const std::string LOGGEDIN = "230"; //user logged in
	const std::string CLOSING_CMD = "421"; //fatal error where the command socket must be closed
	const std::string PWD = "257"; //print working directory successful
    const std::string CWD = "250"; //change directory successful

}
