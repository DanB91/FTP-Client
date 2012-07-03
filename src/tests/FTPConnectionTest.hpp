#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../FTPConnection.hpp"


class FTPConnectionTest : public CppUnit::TestFixture{

	CPPUNIT_TEST_SUITE(FTPConnectionTest);
	CPPUNIT_TEST(testReadLine);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(){
		conn.connect("ftp.freebsd.org", "21");
	}
	void testReadLine(){
		std::string str = conn.readLineFromSocket() ;
		std::cout << str << std::endl;
		CPPUNIT_ASSERT(str.find("220")  != std::string::npos);
	}


private:
	FTPConnection conn;


};
