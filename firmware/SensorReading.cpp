#include "SensorReading.h"

/*#define PRINT(string) (Serial.print(string))*/
#define PRINT(string)

void SensorReading::pushReading(const int deviceId, const int value) {
  char body [50];
  sprintf(body, "{\"deviceId\": %d, \"value\": %d}", deviceId, value);
  PRINT(body);
  String response = webClient.post("/sensorReading", body);
  String responseBody = webClient.getResponseBody(response);
  PRINT("Recieved response: " + responseBody);
}
