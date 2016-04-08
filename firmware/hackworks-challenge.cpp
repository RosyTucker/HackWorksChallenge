#include "WebClient.h"

/*#define PRINT(string) (Serial.print(string))*/
#define PRINT(string)

WebClient::WebClient(const char* _host){
  host = _host;
}

String WebClient::get(const char* endPoint){
  sendRequest("GET", endPoint, NULL);
  return createResponse();
}

String WebClient::post(const char* endPoint, const char* body){
  sendRequest("POST", endPoint, body);
  return createResponse();
}

String WebClient::getResponseBody (String response) {
  int bodyStartIndex = response.indexOf("\n\r") + 4;
  response.remove(0, bodyStartIndex);
  return response;
}

void WebClient::sendRequest(const char* verb, const char* endPoint, const char* body) {
  if (client.connect(host, 80)) {
    PRINT("Connected");

    char requestLineOne [50];
    sprintf(requestLineOne, "%s %s HTTP/1.1", verb, endPoint);

    char requestLineTwo [50];
    sprintf(requestLineTwo, "Host: %s", host);

    client.println(requestLineOne);
    client.println(requestLineTwo);
    client.println("Connection: close");

    if(body != NULL) {
      char contentLength[25];
      sprintf(contentLength, "Content-Length: %d", strlen(body));
      client.println(contentLength);

      client.println("Content-Type: application/json");

      client.println();

      client.println(body);

      client.println();
      client.println();
    } else {
      client.println();
    }
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
