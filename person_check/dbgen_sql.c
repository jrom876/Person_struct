
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
// #include "createHuman.h"

// To install the sqlite3 libraries use these commands:
// sudo apt-get install sqlite3
// sudo apt-get install libsqlite3-dev

#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open("test.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_close(db);
}


// int main(int argc, char** argv)
// {
//     sqlite3* DB;
//     std::string sql = "CREATE TABLE PERSON("
//                       "ID INT PRIMARY KEY     NOT NULL, "
//                       "NAME           TEXT    NOT NULL, "
//                       "SURNAME          TEXT     NOT NULL, "
//                       "AGE            INT     NOT NULL, "
//                       "ADDRESS        CHAR(50), "
//                       "SALARY         REAL );";
//     int exit = 0;
//     exit = sqlite3_open("example.db", &DB);
//     char* messaggeError;
//     exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
//
//     if (exit != SQLITE_OK) {
//         std::cerr << "Error Create Table" << std::endl;
//         sqlite3_free(messaggeError);
//     }
//     else
//         std::cout << "Table created Successfully" << std::endl;
//     sqlite3_close(DB);
//     return (0);
// }
