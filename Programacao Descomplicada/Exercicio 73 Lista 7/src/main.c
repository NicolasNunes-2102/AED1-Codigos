#include <stdio.h>
#include <ctype.h>

typedef struct {
    char sex;
    char olhos;
    char cabelos;
    int idade;
  }hab;
  
void ler(void);
void media(void);
int maior(void);
int barbie(void);

hab habitantes[5];

int main(){
  int menu=1, mid, barbies;
    
  do{

    do{
    if(menu<0||menu>4){
        printf("\nNúmero Inválido!\n");
    }
    printf("\nEscolha função:\n0 - Sair\n1 - Ler dados\n2 - Determinar idade média\n3 - Determinar maior idade\n4 - Mulheres loiras de olho azul, de 18 a 35 anos\n\n");
    scanf("%d", &menu);
    }while(menu<0||menu>4);

  switch (menu) {
    case 0:
      printf("\nSaindo...");
      break;
    case 1: 
      ler();
      break;
    case 2:
      media();
      break;
    case 3:
      mid=maior();
      printf("\nMaior Idade: %d\n", mid);
      break;
    case 4:
      barbies=barbie();
      printf("\nNúmero de pessoas dentro dos parâmetros: %d\n", barbies);
      break;
    }
  }while(menu!=0);
  return 0;
}

void ler(void){
  for(int i=0;i<5;i++){

    //sexo
  
    do{
    printf("Do indivíduo %d, diga o sexo: M / F\n", i+1);
    scanf(" %s", &habitantes[i].sex);
    if(habitantes[i].sex=='m'||habitantes[i].sex=='f'){
        habitantes[i].sex=toupper(habitantes[i].sex);
    }

    if(!(habitantes[i].sex=='M'||habitantes[i].sex=='F')){
        printf("\nValor Inválido!\n");
    }

    }while(!(habitantes[i].sex=='M'||habitantes[i].sex=='F'));

    //olhos
    do{
    printf("Do indivíduo %d, diga a cor dos olhos: A - Azuis / C - Castanhos\n", i+1);
    scanf(" %s", &habitantes[i].olhos);
    if(habitantes[i].olhos=='a'||habitantes[i].olhos=='c'){
        habitantes[i].olhos=toupper(habitantes[i].olhos);
    }

    if(!(habitantes[i].olhos=='A'||habitantes[i].olhos=='C')){
        printf("\nValor Inválido!\n");
    }

    }while(!(habitantes[i].olhos=='A'||habitantes[i].olhos=='C'));

    //cabelo
    do{
    printf("Do indivíduo %d, diga a cor do cabelo: L - Loiro / P - Preto / C - Castanho\n",  i+1);
    scanf(" %s", &habitantes[i].cabelos);
    if(habitantes[i].cabelos=='l'||habitantes[i].cabelos=='p'||habitantes[i].cabelos=='c'){
        habitantes[i].cabelos=toupper(habitantes[i].cabelos);
    }

    if(!(habitantes[i].cabelos=='L'||habitantes[i].cabelos=='P'||habitantes[i].cabelos=='C')){
        printf("\nValor Inválido!\n");
    }

    }while(!(habitantes[i].cabelos=='L'||habitantes[i].cabelos=='P'||habitantes[i].cabelos=='C'));

    //idade
    printf("Do indivíduo %d, diga a idade:\n", i+1);
    scanf("%d", &habitantes[i].idade);
  }
}

void media(void){
  float med;
  med = (habitantes[0].idade+habitantes[1].idade+habitantes[2].idade+habitantes[3].idade+habitantes[4].idade)/4;
  printf("Idade média dos indivíduos: %.2f\n", med);
}
  
int maior(void){
  int maiorIdade=0;
  
  for(int i=0;i<5;i++){
    if(habitantes[i].idade>maiorIdade)
      maiorIdade=habitantes[i].idade;
    }

  return maiorIdade;
}
  
int barbie(void){
  int filtro=0;
  for(int i=0;i<5;i++){
    if(habitantes[i].idade>=18&&habitantes[i].idade<=35&&habitantes[i].cabelos=='L'&&habitantes[i].olhos=='A')
      filtro++;
    }

  return filtro;
}