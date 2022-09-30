#include "headers.h"
#include "Logger.h"
using namespace std;

int return_code;
char* error_message;

Logger::Logger(const char* newName){ //Constructor
    name = newName;


    //--- Creating Database ---
    return_code = sqlite3_open(name, &db); //Creating the database

    if (return_code != SQLITE_OK){ //If database was unable to be created
        fprintf(stderr, "Unable to open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    } else{
        cout << "Successfully created database \"" << name << "\"" << endl;
    }


    // --- Creating table ---
    string temp = name;
    string query = "CREATE TABLE IF NOT EXISTS "+ temp +" (timestamp VARCHAR(255), message VARCHAR(255));";

    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);
    if (return_code != SQLITE_OK){
        cerr << "Error creating table: " << return_code << endl;
        sqlite3_free(error_message);
    }
    else{
        cout << "Table created" << endl;
    }
}

Logger::~Logger() {
    sqlite3_close(db);
}

void Logger::setName(const char *newName) {
    name = newName;
}

string Logger::getName() {
    return name;
}

void Logger::write(const string& message) {
    std::time_t time = std::time(nullptr);
    string timestamp = ctime(&time);

    string temp = name;
    string query = "INSERT INTO " + temp +  " VALUES (\""+ timestamp +"\", \"" + message +"\");";

    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);
    if (return_code != SQLITE_OK){
        cerr << "Error inserting into table " << return_code << endl;
        sqlite3_free(error_message);
    }
    else{
        cout << "\"" + message + "\" inserted into table" << endl;
    }
}

//vector<string> Logger::read_all() {
//    vector<string> logs;
//    string temp = name;
//    string query = "select * from" + temp +";";
//
//    sqlite3_prepare_v2(db, , , , );
//    sqlite3_step();
//    sqlite3_column_text();
//    sqlite3_finalize();
//
//    return logs;
//}




