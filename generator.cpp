#include "headers.h"
#include "Logger.h"

using namespace std;


int main(int argc, char* argv[]) {
    string name;
    vector<char*> messages;
    vector<LogMessage> logs;
    string databaseName = "messages";

    //Creating the database
    Logger generator (databaseName.c_str());

    //Adding every argument to a vector
    for (int i = 1; i < argc; ++i ) {
        messages.push_back(argv[i]);
    }

    //Inserting a random string from the vector to the table
    for (int i = 0; i < messages.size()+2; ++i) {
        int random = rand() % messages.size();
        string value = messages[random];
        generator.write(value);
        messages.erase(messages.begin() + random);
        //Sleep between 0 and 10 seconds
        random = rand() % 10000;
        sqlite3_sleep(random);
    }

    logs = generator.read_all();

    for (LogMessage log: logs) {
        string temp = log.getTimestamp().erase(log.getTimestamp().length()-1) + ": " + log.getMessage().erase(log.getMessage().length());
        cout << temp<< endl;
    }

    generator.~Logger();

    return 0;
}