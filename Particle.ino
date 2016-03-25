#include "WebClient.h"

WebClient webClient = WebClient("hackworks-challenge.herokuapp.com");

void setup() {
  Serial.println("Starting...");
}

void loop() {
 String response = webClient.get("/task");
  String body = getResponseBody(response);
  String destination = getDestinationFromBody(body);

  Serial.println("Recieved Task for: " + destination);

  delay(5000);
}

String getResponseBody (String response) {
  int bodyStartIndex = response.indexOf("\n\r") + 4;
  response.remove(0, bodyStartIndex);
  return response;
}

String getDestinationFromBody (String response) {
  String searchTerm = "\"destination\":\"";
  int firstDestinationIndex = response.lastIndexOf(searchTerm) + searchTerm.length();
  response.remove(0, firstDestinationIndex);
  return response.substring(0, 3);
}
