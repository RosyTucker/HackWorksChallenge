#include "TaskReceiver.h"

Task TaskReceiver::fetch() {
  Task task;
  String response = webClient.get("/task");
  String body = webClient.getResponseBody(response);
  task.destination = getDestinationFromBody(body);
  task.type = getTypeFromBody(body);

  Serial.println("Recieved Task for: " + task.destination + " with type: " + task.type);
  return task;
}

String TaskReceiver::getDestinationFromBody (String body) {
  String searchTerm = "\"destination\":\"";
  int firstDestinationIndex = body.indexOf(searchTerm) + searchTerm.length();
  body.remove(0, firstDestinationIndex);
  return body.substring(0, 3);
}

int TaskReceiver::getTypeFromBody (String body) {
  String searchTerm = "\"type\":";
  int firstTypeIndex = body.indexOf(searchTerm) + searchTerm.length();
  body.remove(0, firstTypeIndex);

  int i = 0;
  while(body.charAt(i) >= '0' && body.charAt(i) <= '9' ) i++;

  return body.substring(0,i).toInt();
}
