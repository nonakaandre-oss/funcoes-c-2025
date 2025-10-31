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
        int resultado = (cpf[posicao] - '0') * multiplicador;
        soma += resultado;
        multiplicador--;
       // printf("%d\n", (cpf[posicao] - '0'));
    }

    int resto = soma % 11;
    if (resto < 2){
        return 0;
    }
    return 11 - resto;
}



int validar(char* cpf) {
    int dv = obter_digito_verificador(cpf,1);
    if (dv != (cpf[9] - '0')){
        return 1;
    } else {
        dv = obter_digito_verificador(cpf,2);
        if(dv != (cpf[10] - '0')){
            return 1;
        }
    }
    return 0;
}


 int main () {
    char* cpf = ler_cpf();

    if(validar(cpf) == 1){
        printf("CPF Invalido\n");
    } else {
        printf("CPF Válido\n");
    }

    return 0;
 }