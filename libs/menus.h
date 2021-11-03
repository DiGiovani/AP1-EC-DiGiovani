#ifndef menus.h
#define menus .h

#include <stdio.h>
#include "stdlib.h"

void clearScreen()
{
    system("cls");
}

extern int MainMenu()
{
    char i = 0;
    clearScreen();
    printf("=============== Bem vindo! ===============\n");
    printf("Digite um comando para prosseguir: \n");
    printf("C - Gerenciar Clientes\n");
    printf("T - Gerenciar Contas\n");
    printf("S - Sair");

    printf("\n> ");

    return (int)i;
}

int ManageClientsMenu()
{
    int i = 0;
    clearScreen();
    printf("=============== Gerenciar Clientes ===============\n");
    printf("Digite um comando para prosseguir: \n");
    printf("C - Cadastrar um cliente\n");
    printf("L - Listar todos os clientes cadastrados\n");
    printf("B - Buscar cliente já cadastrado\n");
    printf("A - Atualizar um cliente cadastrado\n");
    printf("E - Excluir um cliente cadastrado\n");
    printf("S - Sair\n");

    printf("\n> ");

    return i;
}

int ManageAccountsMenu()
{
    int i = 0;
    clearScreen();
    printf("=============== Gerenciar Contas ===============\n");
    printf("Digite um comando para prosseguir:\n");
    printf("R - Listagem de todas as contas cadastradas.\n");
    printf("C - Cadastrar uma conta para um cliente.\n");
    printf("L - Listar todas as contas de um cliente.\n");
    printf("S - Sair\n");

    printf("\n> ");

    return i;
}

int EndMenu()
{
    printf("\n\n============ Operacao Concluida ============\n");
    printf("R - Reiniciar\n");
    printf("S - Sair");

    printf("\n> ");

    return 1;
}

#endif