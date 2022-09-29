#ifndef ASSIGNMENT_1_LOGGER_H
#define ASSIGNMENT_1_LOGGER_H
#include <string>
using namespace std; //Change scope of namespace definition

class logger {
private:
    const char* name;
public:
    explicit logger(const char* newName);
};


void setName(const char* newName);
string getName();
void write(string message);
vector<string> read_all();





#endif