#include "headers.h"
using namespace std;

class log_message{
private:
    string timestamp;
    string message;

public:
    log_message(string newMessage, string newTimestamp){ //Constructor
        message = newMessage;
        timestamp = newTimestamp;
    }

    ~log_message()= default; //Destructor

    string get_message(){ //Setter
        return message;
    }

    string get_timestamp(){ //Setter
        return timestamp;
    }

};