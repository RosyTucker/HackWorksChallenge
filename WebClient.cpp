
#include "WebClient.h"

#ifndef DEBUG
#define PRINT(string) (Serial.print(string))
#endif

#ifdef DEBUG
#define PRINT(string)
#endif

WebClient::WebClient(const char* _host){
  host = _host;
}

String WebClient::get(const char* endPoint){
  sendRequest(endPoint);
  return createResponse();
}

void WebClient::sendRequest(const char* endPoint) {
  if (client.connect(host, 80)) {
    PRINT("Connected");

    char requestLineOne [50];
    sprintf(requestLineOne, "GET %s HTTP/1.1", endPoint);

    char requestLineTwo [50];
    sprintf(requestLineTwo, "Host: %s", host);

    client.println(requestLineOne);
    client.println(requestLineTwo);
    client.println("Connection: close");
    client.println();
  }
}

String WebClient::createResponse() {
  PRINT("Waiting for Response\n\r");

  String response = "";

  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      response.concat(c);
    }
  }

  PRINT("Response is:\n\r");
  PRINT(response);
  PRINT("\n\rFinished\n\r");

  if (!client.connected()) {
    PRINT("Disconnecting\n\r");
    client.stop();
  }
  return response;
}
