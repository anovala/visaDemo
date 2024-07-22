#include "visatype.h"
#include <string>
#include <vector>
#include <visa.h>

class VisaConnector {
public:
  VisaConnector() {}
  bool connect(std::string &resource);
  bool acQuire(std::string &fileName);
  void readData();
  void save(const std::vector<unsigned char> &buf, const std::string &fileName);

private:
  ViSession m_session;
  ViSession m_identifier;
};