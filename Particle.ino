#include "WebClient.h"

WebClient webClient = WebClient("hackworks-challenge.herokuapp.com");

// Declare any fields here

void setup() {
  Serial.println("Starting...");

  // Insert any setup code here
}

void loop() {
  fetchTask();
  delay(5000);
}

void performTask(String destination, int type) {
    // Insert code to perform tasks in here
}


/*********************************************************************
 *   Helper functions for response parsing and making the HTTP call  *
 *********************************************************************/

void fetchTask() {
  String response = webClient.get("/task");
  String body = getResponseBody(response);
  String destination = getDestinationFromBody(body);
  int type = getTypeFromBody(body);

  Serial.println("Recieved Task for: " + destination + " with type: " + type);

  performTask(destination, type);
}

String getResponseBody (String response) {
  int bodyStartIndex = response.indexOf("\n\r") + 4;
  response.remove(0, bodyStartIndex);
  return response;
}

String getDestinationFromBody (String body) {
  String searchTerm = "\"destination\":\"";
  int firstDestinationIndex = body.indexOf(searchTerm) + searchTerm.length();
  body.remove(0, firstDestinationIndex);
  return body.substring(0, 3);
}

int getTypeFromBody (String body) {
  String searchTerm = "\"type\":";
  int firstTypeIndex = body.indexOf(searchTerm) + searchTerm.length();
  body.remove(0, firstTypeIndex);

  int i = 0;
  while(body.charAt(i) >= '0' && body.charAt(i) <= '9' ) i++;

  return body.substring(0,i).toInt();
}
