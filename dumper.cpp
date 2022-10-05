#include "headers.h"
#include "Logger.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<LogMessage> logs;
    string databaseName = argv[1];

    //Displaying every log
    Logger dumper(databaseName.c_str());
    logs = dumper.read_all();
    for (LogMessage log: logs) {
        string temp = log.getTimestamp().erase(log.getTimestamp().length()-1) + ": " + log.getMessage().erase(log.getMessage().length());
        cout << temp<< endl;
    }
    dumper.~Logger();
    return 0;
}