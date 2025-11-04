#include <stdio.h>

#define MAX_ALUNOS 100
#define TAMANHO_MAX_NOME 50

int menu () {
    int opcao;
    do {
    printf("\n========[ Menu]========\n");
    printf("[1] - Registrar Aluno\n");
    printf("[2] - Listar Aluno\n");
    printf("[3] - Salvar arquivo\n");
    printf("[4] - Carregar Arquivo\n");
    printf("[0] - Sair\n");
    printf("Escolha uma opcao (0-4): ");
    scanf("%d", &opcao);
    while(getchar() != '\n'); /*limpa o buffer do teclado*/
    if(opcao < 0 || opcao > 4) {
        printf("Opção invalida\n");
    }
    } while (opcao < 0 || opcao > 4); /*|| indica que seria 'OU'*/

    return opcao;
}

void registrar_aluno(char nomes[][TAMANHO_MAX_NOME], int notas[], int *total) {
    if(*total >= MAX_ALUNOS){
        printf("Limite de alunos atingido\n");
        return;
    }
    printf("Digite o nonme do aluno: ");
    fgets(nomes[*total], TAMANHO_MAX_NOME, stdin);

    printf("Digite a nota do aluno: ");
    scanf("%d", &notas[*total]);
    while(getchar() != '\n'); /*limpa o buffer do teclado*/

    (*total)++;
}

int main (){
    char nomes[MAX_ALUNOS][TAMANHO_MAX_NOME];
    int notas[MAX_ALUNOS];
    int total = 0;
    int opcao;
    do {
    opcao = menu();

    switch (opcao) {
        case 1:
            registrar_aluno(nomes, notas, &total);
            printf("Ultimo valor: %s %d\n", nomes[total -1], notas[total -1]);
            break;
        case 2:
            //listar_alunos(nomes, notas, total);
            break;
        case 3:
            //salvar_arquivo(nomes, notas, total);
            break;
        case 4:
            //carregar_arquivo(nomes, notas, &total);
            break;
        case 0:
            printf("Saindo do programa...\n");
            break;
    }
    } while (opcao != 0);


    return 0;
}