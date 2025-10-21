#include <stdio.h>

double somar(double num_a, double num_b) {  /*float ocupa 32bits e double ocupa 64bits, ou seja, o dobro*/
    return num_a + num_b;
}

double subtrai(double num_a, double num_b) {
    return num_a - num_b;
}

int main () {
   double num_1, num_2;
   int operacao;
   double resultado;

   printf("Digite um número:");
   scanf("%lf", &num_1);

   printf("Digite um número:");
   scanf("%lf", &num_2);

   
    return 0;
}