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
    
        FTPException()
        {
        }
    
		FTPException(const std::string &str) : msg(str)
		{
		}

		virtual const char *what() const throw()
		{
			return msg.c_str();
		}

		virtual ~FTPException() throw()
		{
		}

	private:
		const std::string msg;

};

class NonFatalUnexpectedFTPCodeException : FTPException{
	public:
		NonFatalUnexpectedFTPCodeException(const std::string &msg) : FTPException(msg){} 
};


