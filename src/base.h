#include "visatype.h"
#include <string>
#include <visa.h>

class VisaConnector {
public:
  VisaConnector() {}
  bool connect(std::string &resource);
  bool acQuire(std::string &fileName);
  void readData();

private:
  ViSession m_session;
  ViSession m_identifier;
};