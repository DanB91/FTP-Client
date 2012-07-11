#include "../FTPClient.hpp"
#include "../FTPCodes.hpp"
#define BOOST_TEST_MODULE ftp_client test
#include <boost/test/included/unit_test.hpp>

bool matchesCorrectOutputAndPrintsItOut(std::string output, std::string expectedSubstring)
    {
        std::cout << output << std::endl;
        return output.find(expectedSubstring) != std::string::npos;
    }


BOOST_AUTO_TEST_CASE(test_pwd)
{
    FTPClient client;
    client.connect("ftp.freebsd.org", "21");
    client.login();

     client.printWorkingDirectory();
     BOOST_CHECK(matchesCorrectOutputAndPrintsItOut(client.getResponse(), FTPCodes::PWD));

    

    
}
