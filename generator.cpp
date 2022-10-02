#include "headers.h"
#include "Logger.h"
#include "LogMessage.h"
using namespace std;

int main(int argc, char* argv[]) {
    string name;
    vector<char*> messages;
    vector<LogMessage> logs;

    //Creating the database
    Logger generator ("messages");

    //Adding every argument to a vector
    for (int i = 0; i < argc-1; ++i ) {
        messages.push_back(argv[i]);
    }
    cout << messages.size() << endl;

    //Inserting a random string from the vector to the table FIXME
    for (int i = 0; i < messages.size()+1; ++i) {
        int random = rand() % messages.size();
        string value = messages[random];
        generator.write(value);
        messages.erase(messages.begin() + random);
        random = rand() % 10000; //Sleep between 0 and 10 seconds
        sqlite3_sleep(random);
    }

    logs = generator.read_all();

    for (int i = 0;i<logs.size();i++) {
        cout << logs[i].getTimestamp() << " | " << logs[i].getMessage() << endl;
    }

    generator.~Logger();

    return 0;
}