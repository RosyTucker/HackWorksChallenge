
#include "application.h"

class WebClient {

public:
  WebClient(const char* host);

  String get(const char* endPoint);

private:
  TCPClient client;
  const char* host;
  String createResponse();
  void sendRequest(const char* endPoint);
};
