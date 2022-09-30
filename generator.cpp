#include "headers.h"
#include "Logger.h"
using namespace std;

int main(int argc, char* argv[]) {
    string name;
    vector<char*> messages;

    //Creating the database
    Logger generator ("messages");

    //Adding every argument to a vector
    for (int i = 0; i < argc; ++i ) {
        messages.push_back(argv[i]);
    }

    //Inserting a random string from the vector to the table FIXME
    for (int i = 0; i < messages.size()+1; ++i) {
        int random = rand() % messages.size();
        string value = messages[random];
        generator.write(value);
        messages.erase(messages.begin() + random);
        random = rand() % 10000; //Sleep between 0 and 10 seconds
        sqlite3_sleep(random);
    }


    return 0;
}