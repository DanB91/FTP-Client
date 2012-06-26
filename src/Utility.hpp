/*
 * This class will contain various utility static methods such as toString and fromString 
 */

#pragma once
#include <sstream>
#include "FTPExceptions.hpp"

/*
 * This method takes in a string and outputs the object (normally a primitive) representing it
 */
template<typename T> T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T ret;

	if(!iss >> ret)
		throw FTPException();

	return ret;



}



