#pragma once
#include "application.h"

class WebClient {

public:
  WebClient(const char* host);

  String getResponseBody(String body);

  String get(const char* endPoint);

  String post(const char* endPoint, const char* body);

private:
  TCPClient client;
  const char* host;
  String createResponse();
  void sendRequest(const char* verb, const char* endPoint, const char* body);
};
