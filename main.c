#include "stdio.h"
#include "stdbool.h"
#include <unistd.h>

void clearScreen()
{
  // const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  // write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

int MainMenu() {
  char i;
  clearScreen();

  printf("=============== Bem vindo! ===============\n");
  printf("Digite um comando para prosseguir: \n");
  printf("C - Gerenciar Clientes\n");
  printf("T - Gerenciar Contas\n");
  printf("S - Sair\n");
  scanf("%c", &i);

  return (int) i;
}

int ManageClientsMenu() {
  char j;

  clearScreen();
  printf("=============== Gerenciar Clientes ===============\n");
  printf("Digite um comando para prosseguir: ");
  printf("C - Cadastrar um cliente\n");
  printf("L - Listar todos os clientes cadastrados\n");
  printf("B - Buscar cliente já cadastrado\n");
  printf("A - Atualizar um cliente cadastrado\n");
  printf("E - Excluir um cliente cadastrado\n");
  printf("S - Sair\n");

  scanf("%c", &j);

  return (int) j;
}

int ManageAccountsMenu() {
  char j;
  clearScreen();
  printf("=============== Gerenciar Contas ===============\n");
  printf("Digite um comando para prosseguir: ");
  printf("C - Cadastrar um cliente\n");
  printf("L - Listar todos os clientes cadastrados\n");
  printf("B - Buscar cliente já cadastrado\n");
  printf("A - Atualizar um cliente cadastrado\n");
  printf("E - Excluir um cliente cadastrado\n");
  printf("S - Sair\n");

  scanf("%c", &j);

  return (int) j;
}


int main(void) {
  int menu_i, menu_j, menu_k;
  bool run = true;

  
    menu_i = MainMenu();

    switch(menu_i) {
      case (int) 'c':
      case (int) 'C':
        menu_j = ManageClientsMenu();
        break;

      case (int) 'T':
      case (int) 't':
        menu_j = ManageAccountsMenu();
    }
  
  

}
