#include "TaskReceiver.h"
#include "SensorReading.h"

// Field declarations here
int deviceId = 0;

void setup() {
  Serial.println("Starting...");
  //Setup code here
}

void loop() {
  submitSensorReading();
  performTask();
  delay(1000);
}

void performTask() {
  Task task = TaskReceiver().fetch();
  // Code for acting upon recieved data here
}

void submitSensorReading() {
  // Code for sending data here, format: SensorReading().pushReading(deviceId, sensorReading);
}
