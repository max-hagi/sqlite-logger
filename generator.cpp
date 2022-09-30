#include "headers.h"
#include "Logger.h"
using namespace std;

int main(int argc, char* argv[]) {
    string name;
    vector<char*> messages;

    for (int i = 0; i < argc; ++i ) {
        messages.push_back(argv[i]);
    }

    Logger generator ("messages");
    generator.write("test123");



    return 0;
}