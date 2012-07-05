#pragma once
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../FTPClient.hpp"
#include "../FTPCodes.hpp"

class FTPClientTest : public CppUnit::TestFixture{

	CPPUNIT_TEST_SUITE(FTPClientTest);
	CPPUNIT_TEST(testLogin);
	CPPUNIT_TEST(testPWD);
	CPPUNIT_TEST_SUITE_END();

private:
	FTPClient client;



public:
	bool matchesCorrectOutputAndPrintsItOut(std::string output, std::string expectedSubstring)
	{
		std::cout << output << std::endl;
		return output.find(expectedSubstring) != std::string::npos;
	}


	void setUp(){
		client.connect("ftp.freebsd.org", "21");
	}

	void testLogin(){
		CPPUNIT_ASSERT_NO_THROW(client.login());
		
		CPPUNIT_ASSERT(matchesCorrectOutputAndPrintsItOut(client.getResponse(), "230"));
	}

	void testPWD(){
		client.login();
		CPPUNIT_ASSERT_NO_THROW(client.printWorkingDirectory()); 		
		CPPUNIT_ASSERT(matchesCorrectOutputAndPrintsItOut(client.getResponse(), FTPCodes::PWD));
	}



};
