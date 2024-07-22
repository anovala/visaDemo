#include <string>
#include "src/base.h"
#include <string>
#include <visa.h>

int main(void)
{
    std::string resource("TCPIP::192.168.1.42::INSTR"); 
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