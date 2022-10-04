#include "headers.h"
#include "Logger.h"
using namespace std;

int main(int argc, char* argv[]) {
    string name;
    vector<char*> messages;
    //string databaseName = argv[0];
    string databaseName = "messages";

    //Creating the database

    //databaseName.erase(0,2)
    Logger generator (databaseName.c_str());

    //Adding every argument to a vector
    for (int i = 1; i < argc; ++i ) {
        messages.push_back(argv[i]);
    }

    //Inserting a random string from the vector to the table
    for (int i = 0; i < messages.size(); ++i) { //FIXME
        int random = rand() % messages.size();
        string value = messages[random];
        generator.write(value);
        messages.erase(messages.begin() + random);
        //Sleep between 0 and 10 seconds
        random = rand() % 10000;
        sqlite3_sleep(random);
    }
    return 0;
}


