#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

static int callback(void *outputPtr, int argc, char **argv, char **azColName){
    int i;
    vector<string> *list = reinterpret_cast<vector<string>*>(outputPtr);
    list->push_back(argv[1]);
    return 0;
}

int main(){
    sqlite3* db;
    char *zErrMsg = 0;
    int rc;
    
    rc = sqlite3_open("mail.db", &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    };
    
    string name;
    cout << "Welcome to Cyberdyne!  What is your login name?"<< endl;
    getline(cin, name);
    string password;
    cout << "Thank you "<< name << ".  What is your password?" << endl;
    getline(cin, password);
    
    string sql = "SELECT * FROM users where name='" + name + "' and password='"+password + "'";
    vector<string> results;
    
    rc = sqlite3_exec(db, sql.c_str(), callback, &results, &zErrMsg);
    if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      if (!results.empty()){
        cout << "Welcome to Cyberdyne " << results[0] << endl;
      } else {
        cout << "Not a valid name/password combo.  Try again." << endl;
      }
    }
    sqlite3_close(db);
    return 0;
};
