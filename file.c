#include <stdio.h>

int main (){
   FILE *arquivo;

   arquivo = fopen("teste.txt", "w"); /*o W sempre sobrescreve o conteudo, W+ adiciona*/

   if(arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return 1;
   }

   fprintf(arquivo, "Olá Arquivo!!!\n");

   fclose(arquivo);

    return 0;
}