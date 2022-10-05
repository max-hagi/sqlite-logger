#include "headers.h"
#include "Logger.h"
using namespace std;

//Signal handler to interrupt generator manually
int interrupt = 0;
void signalHandler(int signum){
    cout << "Terminating manually" << endl;
    interrupt = 1;
}

int main(int argc, char* argv[]) {
    string name;
    vector<char*> messages;

    //The code below should dynamically name the generator, but runs into error connecting to table whenever I use it:
    /*
    string databaseName = argv[0];
    databaseName = databaseName.erase(0,2);
    */

    //This is the implementation I had to use to make the logging process function properly:
    string databaseName = "generator";

    //Creating the database
    Logger generator (databaseName.c_str());

    //Adding every argument to a vector
    for (int i = 1; i < argc; ++i ) {
        messages.push_back(argv[i]);
    }


    //Inserting a random string from the vector to the table
    signal(SIGINT, signalHandler);
    int num = messages.size();
    int i = 0;

    //Will keep logging until interrupted with ctr + c or until all parameters are logged
    while (interrupt == 0 && i < num) {
        int random = rand() % messages.size();
        string value = messages[random];
        generator.write(value);
        messages.erase(messages.begin() + random);
        //Sleep between 0 and 10 seconds
        random = rand() % 10000;
        cout << "Sleeping for " << random / 1000 << " seconds" << endl;
        sqlite3_sleep(random);
        i++;
    }
    generator.~Logger();
    return 0;
}


