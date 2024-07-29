#include <string>
#include "src/base.h"
#include <string>
#include <visa.h>
#include <iostream>

int main(void)
{
    std::cout << "IP:"; 
    std::string IP;
    std::cin >> IP;

    std::string resource;//"TCPIP::192.168.1.42::INSTR
    resource = "TCPIP::"+IP+"::INSTR";
    std::string png;
    std::string path;
    std::string absPng;
    VisaConnector connector;
    png = "20240719115034.PNG";
    path = "/INT/SCREEN/";
    absPng = path+png;
    connector.connect(resource);
    connector.acQuire(absPng);
    connector.readData();
    connector.disconnect();

    return 0;
}