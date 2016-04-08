#pragma once

#include "WebClient.h"
#include "application.h"

class SensorReading {
  public:
    void pushReading(const int deviceId, const int value);

  private:
    WebClient webClient = WebClient("hackworks-challenge.herokuapp.com");
};
