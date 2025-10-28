#include <stdio.h>
char* ler_cpf() {
    static char valor[11];
    printf("Digite seu CPF somente com números: ");
    scanf("%11s", valor);
    return valor;
}

int obter_digito_verificador(char* cpf, int ordem) {
    int multiplicador = (ordem == 1) ? 10 : 11; /*operador ternário (operador de distribuição condicional)*/
    int soma = 0;
    int parada = ((ordem == 1) ? 8 : 9);

    for (int posicao = 0; posicao < parada; posicao++) {
        int resultado = cpf[posicao] * multiplicador;
        soma + resultado;
        multiplicador;
    }
    return soma;
}

int validar(char* cpf) {
    return 0;
}


 int main () {
    char* cpf = ler_cpf();
    int resultado = obter_digito_verificador(cpf, 2);


    return 0;
 }