#ifndef ASSIGNMENT_1_LOG_MESSAGES_H
#define ASSIGNMENT_1_LOG_MESSAGES_H
#include "headers.h"
using namespace std;

class log_message {
private:
    string message;
    string timestamp;

public:
    log_message(string newMessage, string newTimestamp);
};

string getMessage();
string getTimestamp();



#endif