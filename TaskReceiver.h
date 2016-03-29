#include "WebClient.h"
#include "application.h"

struct Task {
  int type;
  String destination;
};

class TaskReceiver {
  public:
    Task fetch();

  private:
    WebClient webClient = WebClient("hackworks-challenge.herokuapp.com");
    String getResponseBody (String response);
    String getDestinationFromBody (String body);
    int getTypeFromBody (String body);
};
