#include "TaskReceiver.h"
#include "SensorReading.h"

// Declare any fields here

void setup() {
  Serial.println("Starting...");
  // Insert any setup code here
}

void loop() {
  submitSensorReading();
  performTask();
  delay(2500);
}

void performTask() {
  Task task = TaskReceiver().fetch();
  // Insert code to perform tasks in here, tasks have a destination and a type
}

void submitSensorReading() {
  // Submit sensor readings like this: SensorReading().pushReading(<Your device id>, <your sensor reading> );
  SensorReading().pushReading(1, 1234);
}
