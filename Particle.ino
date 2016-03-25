#include "WebClient.h"

WebClient webClient = WebClient("hackworks-challenge.herokuapp.com");

void setup() {
  Serial.println("Starting...");
}

void loop() {
 String response = webClient.get("/task");
  String body = getResponseBody(response);

  delay(5000);
}

String getResponseBody (String response) {
  int bodyStartIndex = response.indexOf("\n\r") + 4;
  response.remove(0, bodyStartIndex);
  return response;
}
