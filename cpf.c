#include <stdio.h>

int main (){
    char CPF[12]; /*Por ser um numero muito extenso é preciso usar CHAR, assim o sistema vai ler cada numero individualmente*/
    int digito[11]; /*Armazena os caracteres que foram transformados em numeros*/
    int soma,num;
    
    printf("Digite seu CPF somente com números:");
    scanf("%s", CPF);  /*Pedindo para o sistema guardar cada caractere em uma posição do vetor*/

   for(int num=0; num<11; num++){
    digito[num] = CPF[num] - '0'; /*Tranforma os caracteres em numeros usando a tabela ASCII*/
   }
   
   soma = 0;                     /*Subtrair '0' converte o caractere para o seu valor numérico*/
   
   
   for(int num=0; num<9; num++){
    int peso = 10 - num;
    printf("Digito[%d] = %d  Peso = %d  Multiplicação = %d\n", num, digito[num], peso, digito[num] * peso);
        soma += digito[num] * (10-num);
    }     /*soma = soma + digito[num] * (10-num);*/
   
printf("\nSoma ponderada dos 9 primeiros digitos = %d\n", soma);

    return 0;
}