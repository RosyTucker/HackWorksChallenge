#include "TaskReceiver.h"

// Declare any fields here

void setup() {
  Serial.println("Starting...");
  // Insert any setup code here
}

void loop() {
  Task task = TaskReceiver().fetch();
  performTask(task.destination, task.type);
  delay(5000);
}

void performTask(String destination, int type) {
    // Insert code to perform tasks in here
}
