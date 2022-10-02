#ifndef ASSIGNMENT_1_LOGMESSAGE_H
#define ASSIGNMENT_1_LOGMESSAGE_H
#include <string>
using namespace std;

class LogMessage {
private:
    string message;
    string timestamp;

public:
    LogMessage(string newMessage, string newTimestamp);
    string getMessage();
    string getTimestamp();
};

#endif