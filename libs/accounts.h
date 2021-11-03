#ifndef accounts.h
#define accounts .h

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "database.h"

int CreateAccount()
{
    char sql_model[500] = "INSERT INTO accounts(AGENCY, ACCOUNT_NUMBER, CLIENT_ID, BALANCE) VALUES('%s', '%s', '%s', %f);",
         formated_sql[500],
         account_number[6],
         client_id[12];
    char random[50];
    float balance = 0;
    system("cls");
    printf("================= Cadastro Conta ==================\n");
    printf("Numero da agencia: ");
    gets(account_number);
    printf("Numero da conta: ");
    gets(random);
    printf("ID do Cliente: ");
    gets(client_id);

    sprintf(formated_sql, sql_model, account_number, random, client_id, &balance);
    AlterTable(formated_sql);
    printf("Conta criada!");
    return 0;
};

int ListAccounts()
{
    system("cls");
    fflush(stdin);
    char sql_model[500] = "SELECT * FROM accounts ORDER BY ID;";
    AlterTable(sql_model);
}

int ListClientAccounts()
{
    char sql_model[500] = "SELECT * FROM accounts WHERE CLIENT_ID = %s;",
         sql_formatted[50],
         id[50];

    system("cls");
    fflush(stdin);

    printf("Digite o ID do cliente: ");
    gets(id);
    sprintf(sql_formatted, sql_model, id);
    AlterTable(sql_formatted);
}

#endif