#include "FTPConnectionTest.hpp"
#include "FTPClientTest.hpp"
#include <iostream>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>


CPPUNIT_TEST_SUITE_REGISTRATION(FTPConnectionTest);
CPPUNIT_TEST_SUITE_REGISTRATION(FTPClientTest);


int main()
{
	try{
		CppUnit::TextUi::TestRunner runner;
		CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
		runner.addTest( registry.makeTest() );

		runner.run();
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
