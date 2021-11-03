#ifndef client
#define client
#endif

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "database.h"

int CreateClient()
{
    char name[100],
        cpf[12],
        tel[12],
        address[100];
    system("cls");
    fflush(stdin);

    printf("================= Cadastro Cliente ==================");
    printf("\nNome: ");
    gets(name);
    printf("CPF: ");
    gets(cpf);
    printf("Telefone: ");
    gets(tel);
    printf("Endereco: ");
    gets(address);

    char sql_model[500] = "INSERT INTO clients(NAME, CPF, TEL, ADDRESS) VALUES('%s', '%s', '%s', '%s');", formated_sql[500];
    sprintf(formated_sql, sql_model, name, cpf, tel, address);
    AlterTable(formated_sql);
    printf("Cliente criado!");
    return 0;
};

int DeleteClient()
{
    char sql_model_CPF[500] = "DELETE FROM clients WHERE CPF = %s", sql_model_ID[500] = "DELETE FROM clients WHERE ID = %s", formated_sql[500], id[50];
    int choice = 0;

    system("cls");
    fflush(stdin);
    printf("================= Deletar Cliente ==================");

    printf("Escolha o tipo de dado para procura do cliente: \n");
    printf("1 - CPF\n");
    printf("2 - ID\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("CPF: ");
        scanf("%s", id);
        printf("\n%s", id);
        sprintf(formated_sql, sql_model_CPF, id);
        break;

    case 2:
        printf("ID: ");
        scanf("%s", id);
        sprintf(formated_sql, sql_model_ID, id);

        break;
    }
    AlterTable(formated_sql);
    printf("Cliente deletado!");
}

int ListClients()
{
    system("cls");
    fflush(stdin);
    char sql_model[500] = "SELECT * FROM clients ORDER BY NAME;";
    AlterTable(sql_model);
}

int ShowClient()
{
    char sql_ID[200] = "SELECT * FROM clients WHERE ID = %s;",
         sql_CPF[200] = "SELECT * FROM clients WHERE CPF = %s;",
         sql_name[200] = "SELECT * FROM clients WHERE NAME IS LIKE '\%%s%';",
         sql_formatted[500],
         value[100];
    int id_choice;

    system("cls");
    fflush(stdin);

    printf("================= Buscar Cliente ==================");

    printf("Escolha o tipo de dado para procura do cliente: \n");
    printf("1 - ID\n");
    printf("2 - CPF\n");
    printf("3 - Nome\n");
    printf("> ");
    scanf(" %d", &id_choice);
    fflush(stdin);

    switch (id_choice)
    {
    case 1:
        printf("Digite o ID: ");
        gets(value);
        sprintf(sql_formatted, sql_ID, value);
        break;
    case 2:
        printf("Digite o CPF: ");
        gets(value);
        sprintf(sql_formatted, sql_CPF, value);
        break;
    case 3:
        printf("Digite o nome: ");
        gets(value);
        sprintf(sql_formatted, sql_name, value);
        break;
    }

    AlterTable(sql_formatted);
    return 0;
}

int UpdateClients()
{
    char sql_update_name[150] = "UPDATE clients SET NAME = '%s'",
         sql_update_tel[150] = "UPDATE clients SET TEL = '%s'",
         sql_update_address[150] = "UPDATE clients SET ADDRESS = '%s'",
         sql_where[150],
         sql_model[500],
         sql_formatted[500],
         id[100],
         prop_value[100];
    int id_choice, prop_choice;

    system("cls");

    printf("================= Atualizar Cliente ==================\n");
    fflush(stdin);
    printf("Escolha o tipo de dado para procura do cliente: \n");
    printf("1 - CPF\n");
    printf("2 - ID\n");
    scanf("%d", &id_choice);
    fflush(stdin);

    switch (id_choice)
    {
    case 1:
        printf("Digite o CPF: ");
        scanf("%s", id);
        strcpy(sql_where, " WHERE CPF = '%s';");
        break;

    case 2:
        printf("Digite o ID: ");
        scanf("%s", id);
        strcpy(sql_where, " WHERE ID = %s;");

        break;
    }
    fflush(stdin);

    printf("Selecione a propriedade para ser alterada: \n");
    printf("1 - Nome\n");
    printf("2 - Telefone\n");
    printf("3 - Endereco\n");
    scanf(" %d", &prop_choice);
    fflush(stdin);

    switch (prop_choice)
    {
    case 1:
        printf("Digite o novo nome: ");
        gets(prop_value);
        break;
    case 2:
        printf("Digite o novo telefone: ");
        gets(prop_value);
        break;
    case 3:
        printf("Digite o novo endereco: ");
        gets(prop_value);
        break;
    }
    fflush(stdin);

    switch (id_choice)
    {
    case 1:
        switch (prop_choice)
        {
        case 1:
            strcpy(sql_model, sql_update_name);
            strcat(sql_model, sql_where);
            sprintf(sql_formatted, sql_model, prop_value, id);
            break;
        case 2:
            strcpy(sql_model, sql_update_tel);
            strcat(sql_model, sql_where);
            sprintf(sql_formatted, sql_model, prop_value, id);
            break;
        case 3:
            strcpy(sql_model, sql_update_address);
            strcat(sql_model, sql_where);
            sprintf(sql_formatted, sql_model, prop_value, id);
            break;
        }
    case 2:
        switch (prop_choice)
        {
        case 1:
            strcpy(sql_model, sql_update_name);
            strcat(sql_model, sql_where);
            sprintf(sql_formatted, sql_model, prop_value, id);
            break;
        case 2:
            strcpy(sql_model, sql_update_tel);
            strcat(sql_model, sql_where);
            sprintf(sql_formatted, sql_model, prop_value, id);
            break;
        case 3:
            strcpy(sql_model, sql_update_address);
            strcat(sql_model, sql_where);
            sprintf(sql_formatted, sql_model, prop_value, id);
            break;
        }
    }
    fflush(stdin);

    // printf("%s", sql_formatted);
    AlterTable(sql_formatted);
    printf("Informação do cliente atualizada!");
    return 0;
}
