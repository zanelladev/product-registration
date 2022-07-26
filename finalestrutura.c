#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct {
  int id_produtos;
  char desc_produto[50];
  float qtd_estoque;
  float val_unit;
} Produto;

int produtosIndex = 0;

void opcaoinvalida(){
    printf("\nOp��o inv�lida!");
    printf("\n\nPrecione ENTER para voltar ao menu.");
    getchar();
}

void incluir(Produto produtos[]) {

  produtos[produtosIndex].id_produtos = produtosIndex + 1;
  char seguranca[50];

  system("cls");

  printf("                         Adicionando Item                        \n\n");

  printf("Digite a descri�ao do produto: ");
  gets(seguranca);
  fflush(stdin);

  if(strcmp(seguranca, "") != 0 && strlen(seguranca) <= 50){

  sprintf(produtos[produtosIndex].desc_produto, "%s", seguranca);

  printf("Digite a quantidade em estoque do produto: ");
  scanf("%f", &produtos[produtosIndex].qtd_estoque);
  fflush(stdin);

  printf("Digite o pre�o unitario do produto: R$");
  scanf("%f", &produtos[produtosIndex].val_unit);
  fflush(stdin);

  produtosIndex++;

  }else{
    if (strcmp(seguranca, "") == 0){
      printf("\n� obrigat�ria a inser��o de uma descri��o!");
    } else{
      printf("\nA descri��o excedeu o limite de 50 caracteres!");
    }
  }

  printf("\n\nPrecione ENTER para voltar ao menu.");
  getchar();
}

void pesquisar(Produto produtos[]) {

  char desc[50];
  int i;

  system("cls");

  printf("                          Pesquisa Item                         \n");

  printf("\nDigite a descri��o do produto: ");
  gets(desc);
  fflush(stdin);

  for(i = 0; i < (int)strlen(desc); i++) {
    desc[i] = tolower(desc[i]);
  }

  if(produtosIndex > 0){
    system("cls");
    printf("                        Itens Pesquisados                       \n");
    for(i = 0; i < produtosIndex; i++) {
    for(int j = 0; j < (int)strlen(produtos[i].desc_produto); j++) {
      produtos[i].desc_produto[j] = tolower(produtos[i].desc_produto[j]);
    }

    if(strstr(produtos[i].desc_produto, desc)) {

      printf("\n+----+---------------+-----------------------+----------------+\n");
      printf("| id | Descri��o     | Quantidade em estoque | Valor unit�rio |\n");
      printf("+----+---------------+-----------------------+----------------+\n");
      printf("| %d  | %-14s| %.1f                   | %.2f           |\n", produtos[i].id_produtos, produtos[i].desc_produto ,produtos[i].qtd_estoque, produtos[i].val_unit);
      printf("+----+---------------+-----------------------+----------------+\n");
    } else {
      printf("\nProduto n�o encontrado.");
    }

  }
  }else{
    system("cls");
    printf("\nNenhum produto cadastrado!");
  }
  printf("\n\nPrecione ENTER para voltar ao menu.");
  getchar();
}

void listar(Produto produtos[]) {
  int i;
  float estoque = 0, valorEstoque = 0;

  system("cls");

  printf("                        Lista de Produtos                       \n");
  printf("+----+---------------+-----------------------+----------------+\n");
  printf("| id | Descri��o     | Quantidade em estoque | Valor unit�rio |\n");
  printf("+----+---------------+-----------------------+----------------+\n");
  for(i = 0; i < produtosIndex; i++) {
    printf("| %d  | %-14s| %.1f                   | %.2f           |\n", produtos[i].id_produtos, produtos[i].desc_produto ,produtos[i].qtd_estoque, produtos[i].val_unit);
    estoque += produtos[i].qtd_estoque;
    valorEstoque += (produtos[i].val_unit * produtos[i].qtd_estoque);
  }
  printf("+----+---------------+-----------------------+----------------+\n");

  printf("\n+--------------------------------------------+----------------+\n");
  printf("| Quantidade de itens em estoque             | %.1f            |\n", estoque);
  printf("| Valor total dos itens em estoque           | R$%.2f         |\n", valorEstoque);
  printf("+--------------------------------------------+----------------+\n");

  printf("\n\nPrecione ENTER para voltar ao menu.");
  getchar();
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  Produto produtos[20];
  int opcao;

  do {
    system("cls");

    printf("+-------------------------------------------------------------+\n");
    printf("|                       SISTEMA DE ESTOQUE                    |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("| [1] - Incluir                                               |\n| [2] - Pesquisar                                             |\n| [3] - Listar                                                |\n| [4] - Finalizar                                             |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("\n\nDigite a op��o desejada: ");
    scanf("%i", &opcao);
    fflush(stdin);

    opcao == 1 ? incluir(produtos) : opcao == 2 ? pesquisar(produtos) :
    opcao == 3 ? listar(produtos) : opcao == 4 ? printf("\nObrigado por usar o programa!") : opcaoinvalida();

  } while(opcao != 4);

  return 0;
}
