#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// To install the sqlite3 libraries use these commands:
// sudo apt-get install sqlite3
// sudo apt-get install libsqlite3-dev

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("mytable.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   // sql = "CREATE TABLE COMPANY("  \
   //    "ID INT PRIMARY KEY     NOT NULL," \
   //    "NAME           TEXT    NOT NULL," \
   //    "AGE            INT     NOT NULL," \
   //    "ADDRESS        CHAR(50)," \
   //    "SALARY         REAL );";

// Insert values into database
   sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
            "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
            "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
            "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
            "VALUES (4, 'Gomer', 34, 'Raleigh', 75000.00 ); "   \
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
            "VALUES (5, 'Mark', 25, 'Rich-Mond ', 65000.00 );";


   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}
