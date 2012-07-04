#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../FTPConnection.hpp"


class FTPConnectionTest : public CppUnit::TestFixture{

	CPPUNIT_TEST_SUITE(FTPConnectionTest);
	CPPUNIT_TEST(testReadLine);
	CPPUNIT_TEST(testWriteLine);
	CPPUNIT_TEST_SUITE_END();

private:
	FTPConnection conn;


public:
	void setUp(){
		conn.connect("ftp.freebsd.org", "21");
	}
	void testReadLine(){
		std::string str = conn.readLine() ;
		std::cout << str << std::endl;
		CPPUNIT_ASSERT(str.find("220") != std::string::npos);
	}

	void testWriteLine(){
		conn.readLine() ;
		this->conn.writeLine("USER anonymous\r\n");
		std::string str = conn.readLine();
		std::cout << str << std::endl;
		CPPUNIT_ASSERT(str.find("331") != std::string::npos);
	}



};
