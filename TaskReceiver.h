
#include "application.h"
#include "WebClient.h"

struct Task {
  int type;
  String destination;
};

class TaskCollector {

  public:
    Task fetch();

  private:
    WebClient webClient = WebClient("hackworks-challenge.herokuapp.com");
    String getResponseBody (String response);
    String getDestinationFromBody (String body);
    int getTypeFromBody (String body);
};
