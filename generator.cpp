#include "headers.h"
#include "logger.h"
using namespace std;

int main(int argc, char* argv[]) {
    string name;
    vector<char*> messages;

    for (int i = 0; i < argc; ++i ) {
        messages.push_back(argv[i]);
    }

    logger("messages");


    return 0;


}