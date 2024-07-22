#include "visatype.h"
#include <string>
#include <vector>
#include <visa.h>
#include "../global/globa.h"

extern "C" MVISA_LIB void somefunc();

class MVISA_LIB VisaConnector {
public:
  VisaConnector() {}
  bool connect(std::string &resource);
  bool acQuire(std::string &fileName);
  void readData();
  void save(const std::vector<unsigned char> &buf, const std::string &fileName);
  void disconnect();

private:
  ViSession m_session;
  ViSession m_identifier;
};
