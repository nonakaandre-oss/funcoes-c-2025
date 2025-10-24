#include <stdio.h>

double somar(double num_a, double num_b) {  /*float ocupa 32bits e double ocupa 64bits, ou seja, o dobro*/
    return num_a + num_b;
}

double subtrair(double num_a, double num_b) {
    return num_a - num_b;
}

int main () {
   double num_1, num_2;
   int operacao;
   double resultado;

   printf("Digite um número:");
   scanf("%lf", &num_1);   /*lf = long float*/

   printf("Digite um número:");
   scanf("%lf", &num_2);

   printf("Selecione a operação:\n");
   printf("1 - Soma\n");
   printf("2 - Subtrair\n");
   printf(":");
   scanf("%d", &operacao);

   switch (operacao) {  /*o switch é uma estrutura menos utilizada. Ele só consegue avaliar igualdades*/
      case 1:           /*O switch não consegue ler número decimais. É usado somente em int, string e char*/
          resultado = somar(num_1, num_2);
          break;   /*O break para a execução*/
      case 2:
          resultado = subtrair(num_1, num_2);
          break;
          default: /*É um opcional dentro do switch*/
             printf("Opção invalida\n");    
   }

    printf("Resultado: %.2lf\n", resultado); /**/
    return 0;
}