#ifndef ASSIGNMENT_1_LOGGER_H
#define ASSIGNMENT_1_LOGGER_H
#include <string>
#include "LogMessage.h"
using namespace std; //Change scope of namespace definition

class Logger {
private:
    const char* name;
    sqlite3* db;
public:
    explicit Logger(const char* newName);
    ~Logger();
    void setName(const char* newName);
    string getName();
    void write(const string& message);
    vector<LogMessage> read_all();
};

#endif