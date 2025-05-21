#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Estrutura para definir os atributos de mercado
#define NUM_PRODUTOS 5
#define NUM_MERCADOS 4
typedef struct{
  char* nome;
  float preço[NUM_PRODUTOS];
  float soma;
} Supermercado;
// Estrutura para definir os atributos de produto
typedef struct{
  char* nome;
  float média;
} Produto;
// dando os valores das variáveis de mercados
Supermercado mercados[NUM_MERCADOS] = {
  {"carrefour", {5.1, 4.98, 5, 5.8, 23.12}}, {"guanabara", {4.98, 4.89, 5.1, 6.22, 23.1}}, {"mundial", {5.02, 5.1, 4.98, 6.1, 23.04}}, {"prezunic", {4.87, 4.9, 4.8, 5.98, 203.16}}
};
// dando os valores das variáveis de produtos
Produto produtos[NUM_PRODUTOS] = {
  {"arroz"}, {"feijão"}, {"açúcar"}, {"óleo"}, {"café"}
};

void lerProdutos(char* mercado, char* produto){
  int x = 0, y = 0;
  // passar mercado pra caixa baixa
 while(mercado[x]){
    mercado[x] = tolower(mercado[x]);
    x++;
  }
  // passar produto pra caixa baixa
  while(produto[y]){
    produto[y] = tolower(produto[y]);
    y++;
  }
  for(int i = 0; i < NUM_MERCADOS; i++){
    // comparar se mercado está na lista
    if(strcmp(mercados[i].nome, mercado) == 0){
      x = i;
      break;
    }
    
  }
  for(int i = 0; i < NUM_PRODUTOS; i++){
    // comparar se produto está na lista
    if(strcmp(produtos[i].nome, produto) == 0){
      y = i;
      break;
    }
  }
  printf("%s %s: %.2f\n", mercados[x].nome, produtos[y].nome, mercados[x].preço[y]);
}
void Soma(char* mercado){
  int x =0;
  // passar mercado pra caixa baixa
  while(mercado[x]){
    mercado[x] = tolower(mercado[x]);
    x++;
  }
  for(int i = 0; i < NUM_MERCADOS; i++){
    // comparar se mercado está na lista
    if(strcmp(mercados[i].nome, mercado) == 0){
      x = i;
      break;
    }
  }
  // zerando soma
  mercados[x].soma = 0;
  // adicionando preço em soma
  for(int i = 0; i < NUM_PRODUTOS; i++){
    mercados[x].soma += mercados[x].preço[i];
  }
  printf("A cesta básica ficará %.2f\n", mercados[x].soma);
}
void MenorSoma(){
  float arr[NUM_MERCADOS];
  // somando preços de cada mercado
  for(int i = 0; i < NUM_MERCADOS; i++){
    mercados[i].soma = 0;
    for(int j = 0; j < NUM_PRODUTOS; j++){
      mercados[i].soma += mercados[i].preço[j];
    }
    // colocando soma em uma lista
    arr[i] = mercados[i].soma;
  }
  float arr_menor = arr[0];
  int ind_menor = 0;
  // comparando para qual valor é melhor e pegar o índice dele
  for(int i = 0; i < NUM_MERCADOS; i++){
    if(arr_menor > arr[i]){
      arr_menor = arr[i];
      ind_menor = i;
    }
  }
  printf("O menor valor cesta básica será %.2f no mercado %s\n", arr_menor, mercados[ind_menor].nome);
}
void Media(char* produto){
  // passar produto pra caixa baixa
  int x = 0;
  while(produto[x]){
    produto[x] = tolower(produto[x]);
    x++;
  }
  for(int i = 0; i < NUM_PRODUTOS; i++){
    if(strcmp(produtos[i].nome, produto) == 0){
      x = i;
      break;
    }
  }
  // zerando média
produtos[x].média = 0;
  // somando preços de um produto de cada mercado e passando a média
  for(int i = 0; i < NUM_MERCADOS; i++){
    produtos[x].média += mercados[i].preço[x];
  }
  produtos[x].média /= NUM_MERCADOS;
  printf("A média dos produtos ficará %.2f\n", produtos[x].média);
}
int main(){
  char mercado[] = "carrefour";
  char produto[] = "arroz";
  Media(mercado);
  return 0;
}
