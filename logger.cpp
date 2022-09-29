#include "headers.h"
using namespace std;

class logger {
private:
    const char* name; //Program name

public:
    explicit logger(const char* newName){ //Constructor
        name = newName;

        int return_code;
        sqlite3* db;
        char* error_message;

        return_code = sqlite3_open(name, &db); //Creating the database

        if (return_code != SQLITE_OK){ //If database was unable to be created
            fprintf(stderr, "Unable to open database: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
        } else{
            cout << "Successfully created database " << name << endl;
        }


        string sql = "CREATE TABLE IF NOT EXIST messages (timestamp VARCHAR(255), message VARCHAR(255));";

        return_code = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error_message); //Creating a table
        if (return_code != SQLITE_OK){
            cerr << "Error creating table" << endl;
            sqlite3_free(error_message);
        } else{
            cout << "Table created" << endl;
        }

        sqlite3_close(db); //Closing database after successful creation

    }


    string getName() {
        return name;
    }

    void setName(const char* new_name) { //
        name = new_name;
    }



    ~logger()= default; //Destructor



    void write(const char* &message){ //FIXME
        std::time_t time = std::time(0);
        string timestamp = ctime(&time);

        string query = "insert into messages values (\"time\", \"message\");";
    }



    vector<string> read_all(){
        string query = "select * from app-name;";

        return NULL;
    }

};