#ifndef database.h
#define database .h

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3/sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("----------------------------------------");

    printf("\n");
    return 0;
}

int OpenDatabase()
{
    char *err, *clients_table_creation_sql, *zErrMsg = 0, *accounts_table_creation_sql;
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("database.sql", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    else
    {
        fprintf(stderr, "Opened database sucessfully\n");
    }

    clients_table_creation_sql = "CREATE TABLE IF NOT EXISTS clients("
                                 "ID INTEGER PRIMARY KEY   AUTOINCREMENT,"
                                 "NAME           CHAR[100] NOT NULL,"
                                 "CPF            CHAR[11]  NOT NULL,"
                                 "TEL            CHAR[9]   NOT NULL,"
                                 "ADDRESS        CHAR[100] NOT NULL);";

    rc = sqlite3_exec(db, clients_table_creation_sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        // fprintf(stdout, "Table created successfully\n");
    }

    accounts_table_creation_sql = "CREATE TABLE IF NOT EXISTS accounts("
                                  "ID INTEGER PRIMARY KEY   AUTOINCREMENT,"
                                  "AGENCY         CHAR[6]   NOT NULL,"
                                  "ACCOUNT_NUMBER CHAR[6]   NOT NULL,"
                                  "CLIENT_ID      INT       NOT NULL,"
                                  "BALANCE        DECIMAL   NOT NULL,"
                                  "FOREIGN KEY (CLIENT_ID) REFERENCES clients(ID));";

    rc = sqlite3_exec(db, accounts_table_creation_sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        // fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    return 0;
}

static int AlterTable(char *sql)
{
    sqlite3 *db;
    int rc;
    char *zErrMsg, *sql_stmt;

    rc = sqlite3_open("database.sql", &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    else
    {
        // fprintf(stderr, "Opened database sucessfully\n");
    }

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        // fprintf(stdout, "Table Altered Sucessfully.\n");
    }

    sqlite3_close(db);
}

#endif