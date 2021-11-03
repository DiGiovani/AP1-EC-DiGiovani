#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "libs/menus.h"
#include "libs/database.h"
#include "libs/client.h"
#include "libs/accounts.h"

int main(void)
{
    char menu_i, menu_j, menu_k;
    int step = 0, run = 0;
    OpenDatabase();

    do
    {
        // bem vindo
        if (step == 0)
        {
            MainMenu();
            scanf(" %c", &menu_i);
            menu_i = tolower(menu_i);
            step = 1;
        }

        if (step == 1)
        {
            switch (menu_i)
            {
                // clientes
            case (int)'c':
                ManageClientsMenu();
                scanf(" %c", &menu_j);
                menu_j = tolower(menu_j);
                step = 2;
                break;
                // contas
            case (int)'t':
                ManageAccountsMenu();
                scanf(" %c", &menu_j);
                menu_j = tolower(menu_j);
                step = 3;
                break;
            case (int)'s':
                run = 1;
                step = 10;
                break;
            }
        }
        // clientes
        if (step == 2)
        {
            switch ((int)menu_j)
            {
            case (int)'c':
                CreateClient();
                step = 4;

                break;
            case (int)'l':
                ListClients();
                step = 4;

                break;
            case (int)'b':
                ShowClient();
                step = 4;

                break;
            case (int)'a':
                UpdateClients();
                step = 4;

                break;
            case (int)'e':
                DeleteClient();
                step = 4;

                break;
            case (int)'s':
                step = 1;
                break;
            default:
                printf("Valor: %c", menu_j);
            }
        }
        // contas
        if (step == 3)
        {
            switch ((int)menu_j)
            {
            case (int)'r':
                ListAccounts();
                step = 4;

                break;
            case (int)'c':
                fflush(stdin);
                CreateAccount();
                step = 4;
                break;
            case (int)'l':
                ListClientAccounts();
                step = 4;

                break;

            case (int)'s':
                step = 1;
                break;
            default:
                printf("Valor: %c", menu_j);
            }
        }
        if (step == 4)
        {
            fflush(stdin);
            EndMenu();
            scanf(" %c", menu_k);
            menu_k = tolower(menu_k);
            step = 5;
        }

        switch ((int)menu_k)
        {
        case 'r':
            break;
        case 's':
            step = 10;
            menu_j = 0;
            menu_k = 0;
            run = 1;
            break;
        }

        step = 0;
    } while (run == 0);
}
