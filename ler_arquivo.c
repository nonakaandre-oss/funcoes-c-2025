#include <stdio.h>

int main () {
    FILE *arquivo;
    char linha[256];

    arquivo = fopen("teste.txt", "rt");

    if(arquivo == NULL) {
        printf("Não foi possivel ler o arquivo.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
    printf("%s", linha);
    }
    fclose(arquivo);

    return 0;
}