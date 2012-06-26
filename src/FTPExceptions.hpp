/*
 * This object inherits from the excpetion class and allows you to put a
 * custom message into the expcetion
 */

#pragma once

#include <iostream>
#include <exception>


class FTPException : public std::exception
{

	public:
		MsgException(std::string str) : msg(str)
		{
		}

		virtual const char *what() const
		{
			return msg.c_str();
		}

		virtual ~MsgException() 
		{
		}
	
	private:
		std::string msg;

};


