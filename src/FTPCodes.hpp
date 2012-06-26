/*
 * This file contains all the possible FTP codes wrapped in a class 
 */

#pragma once 

namespace FTPCodes{

	const int RDY_FOR_LOGIN = 220; //ready for login
	const int USR_GOOD = 331; //user is good, input password
	const int LOGGEDIN = 230; //user logged in
	const int CLOSING_CMD = 421; //fatal error where the command socket must be closed
	const int PWD = 257; //print working directory successful
}
