#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Coordenador: Lauro Víctor

Grupo: Phelippe Schnel, Brener, Bruno

*/

struct cliente {
  char nome[50];
  char sexo;
  int idade;
};

typedef struct cliente cliente;

struct venda {
  int itens;
  int num_sabores;
  float valor_total;
  cliente cliente;
};

typedef struct venda venda;

void cadastrar_cliente(cliente *c);
void cadastrar_venda(venda *v, int num_vendas, FILE *file);

int main(void) {

  FILE *file;
  file = fopen("registros.txt", "a");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return 1;
  }

  int seletor;

  do {
    printf("\n ###       Bem-Vindo ao Dev Gelados       ###\n\n");
    printf(" # 1) Cadastrar novas vendas                #\n");
    printf(" # 2) Visualizar venda através de cliente   #\n");
    printf(" # 3) Ver informação de todas as vendas     #\n");
    printf(" # 4) Encerrar programa                     #\n");
    printf("\nDigite a opção desejada: ");
    scanf("%d", &seletor);

    switch (seletor) {
    case 1: {
      int num_vendas;
      printf("Digite a quantidade de vendas que deseja cadastrar: ");
      scanf("%d", &num_vendas);

      venda *vendas = (venda *)malloc(num_vendas * sizeof(venda));
      if (vendas == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
      }

      for (int i = 0; i < num_vendas; i++) {
        printf("\nCadastro da venda %d\n", i + 1);
        cadastrar_cliente(&vendas[i].cliente);
        cadastrar_venda(&vendas[i], num_vendas, file);
      }

      printf("\nCadastro realizado com sucesso!\n");

      free(vendas);
      break;
    }
    case 2:
      printf("Visualizar venda através do cliente\n");
      break;
    case 3:
      printf("Informação de vendas\n");
      break;
    case 4:
      printf("Programa encerrando...\n");
      printf("Programa encerrado.\n");
      break;
    default:
      printf("Opção inválida\n");
      break;
    }

  } while (seletor != 4);

  fclose(file);
  return 0;
}

void cadastrar_cliente(cliente *c){
  getchar();
  printf("Digite o nome do cliente: ");
  fgets(c->nome, sizeof(c->nome), stdin);
  c->nome[strcspn(c->nome, "\n")] = '\0';
  if (strlen(c->nome) < 3) {
    printf("\nErro: Nome inválido, o nome do cliente deve possuir no mínimo 3 letras.\n");
    printf("\nDigite o nome do cliente novamente: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';
  }
  printf("Digite o sexo do cliente (M/F/N): ");
  scanf(" %c", &c->sexo);
  if (c->sexo != 'M' && c->sexo != 'm' && c->sexo != 'F' && c->sexo != 'f' && c->sexo != 'N' && c->sexo != 'n'){
    printf("\nErro: Sexo inválido, M - Masculino, F - Feminino ou N - Prefiro não dizer.");
    printf("\nDigite o sexo novamente: ");
    scanf(" %c", &c->sexo);
  }
  getchar();
  printf("Digite a idade do cliente: ");
  scanf("%d", &c->idade);
  if (c->idade < 0) {
    printf("\nErro: Idade inválida, o número deve ser positivo.");
    printf("\nDigite a idade novamente: ");
    scanf("%d", &c->idade);
  }
}

void cadastrar_venda(venda *v, int num_vendas, FILE *file){
  printf("Digite o número de itens da venda: ");
  scanf("%d", &v->itens);
  if (v->itens < 0) {
    printf("\nErro: Número de itens inválido, o número deve ser positivo.\n");
    printf("\nDigite o número de itens novamente: ");
    scanf("%d", &v->itens);
  }
  printf("Digite o número de sabores presentes na venda: ");
  scanf("%d", &v->num_sabores);
  if (v->num_sabores < 0) {
    printf("\nErro: Número de sabores inválido, o número deve ser positivo.\n");
    printf("\nDigite o número de sabores novamente: ");
    scanf("%d", &v->num_sabores);
  }
  printf("Digite o valor total da compra: ");
  scanf("%f", &v->valor_total);
  if (v->valor_total < 0) {
    printf("\nErro: Valor da compra inválido, o número deve ser positivo.\n");
    printf("\nDigite o valor da compra novamente: ");
    scanf("%f", &v->valor_total);
  }

  fprintf(file, "Cliente: %s\n", v->cliente.nome);
  fprintf(file, "Sexo do cliente: %c\n", v->cliente.sexo);
  fprintf(file, "Idade do cliente: %d\n", v->cliente.idade);
  fprintf(file, "Número de itens: %d\n", v->itens);
  fprintf(file, "Número de sabores: %d\n", v->num_sabores);
  fprintf(file, "Valor total: %.2f\n", v->valor_total);
  fprintf(file, "--------------------------\n");
}