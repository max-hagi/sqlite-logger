#include "LogMessage.h"
using namespace std;


LogMessage::LogMessage(string newMessage, string newTimestamp){
        message = std::move(newMessage);
        timestamp = std::move(newTimestamp);
}

string LogMessage::getMessage() {
    return message;
}

string LogMessage::getTimestamp(){
    return timestamp;
}



