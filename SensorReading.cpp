#include "SensorReading.h"

void SensorReading::pushReading(const int deviceId, const int value) {
  char body [50];
  sprintf(body, "{\"deviceId\": %d, \"value\": %d}", deviceId, value);
  Serial.println(body);
  String response = webClient.post("/sensorReading", body);
  String responseBody = webClient.getResponseBody(response);
  Serial.println("Recieved response: " + responseBody);
}
