#include "DbController.h"
#include<iostream>




static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

DbController::DbController()
{
	initDb();
}


DbController::~DbController()
{
	
}


void DbController::initDb()
{
	int rc = sqlite3_open("test.db", &mDb);
	if (rc == SQLITE_OK)
	{
		char *zErrMsg = 0;
		int rc;
		char *sql;
		const char* data = "Callback function called";
		std::cout << "db created successfully";
		sql = "CREATE TABLE COMPANY("  \
			"ID INT PRIMARY KEY     NOT NULL," \
			"NAME           TEXT    NOT NULL," \
			"AGE            INT     NOT NULL," \
			"ADDRESS        CHAR(50)," \
			"SALARY         REAL );";

		/* Execute SQL statement */
		rc = sqlite3_exec(mDb, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else{
			fprintf(stdout, "Table created successfully\n");
		}
	}
	else
	{
		std::exit(0);
	}
}

void DbController::insertData()
{
	if (mDb)
	{
		/* Create SQL statement */
		char * sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
			"VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
			"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
			"VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
			"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
			"VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
			"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
			"VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

		/* Execute SQL statement */
		char *errMsg = nullptr;
		int rc = sqlite3_exec(mDb, sql, callback, 0, &errMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", errMsg);
			sqlite3_free(errMsg);
		}
		else{
			fprintf(stdout, "Records created successfully\n");
		}
	}
}

void DbController::readData(std::list < std::string > &)
{
	if (mDb)
	{
		char *zErrMsg = 0;
		int rc;
		char *sql;
		const char* data = "Callback function called";		

		/* Create SQL statement */
		sql = "SELECT * from COMPANY";

		/* Execute SQL statement */
		rc = sqlite3_exec(mDb, sql, callback, (void*)data, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else{
			fprintf(stdout, "Operation done successfully\n");
		}
	}
}