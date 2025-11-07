#include <stdio.h>

#define MAXIMO_ALUNOS 100
#define TAMANHO_MAXIMO_NOME 50

int menu() {
    int opcao;
    do {
        printf("\n========[ Menu ]========\n");
        printf("[1] - Registrar Aluno\n");
        printf("[2] - Listar Alunos\n");
        printf("[3] - Salvar em Arquivo\n");
        printf("[4] - Carregar Arquivo\n");
        printf("[0] - Sair\n");
        printf("Escolha uma Opção (0-4): ");
        scanf("%d", &opcao);
        while (getchar() != '\n');
        if(opcao < 0 || opcao > 4) {
            printf("Opção Inválida\n");
        }
    } while (opcao < 0 || opcao > 4);
    
    return opcao;
}

void registrar_aluno(char nomes[][TAMANHO_MAXIMO_NOME], int notas[], int *total) {
    if(*total >= MAXIMO_ALUNOS) {
        printf("Limite de alunos atingido\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    fgets(nomes[*total], TAMANHO_MAXIMO_NOME, stdin);

    int indice = 0;
    while (nomes[*total][indice] != '\0')
    {
        if(nomes[*total][indice] == '\n') {
            nomes[*total][indice] = '\0';
            break;
        }
        indice++;
    }

    printf("Digite a nota: ");
    scanf("%d", &notas[*total]);
    while (getchar() != '\n');

    (*total)++;
}

void listar_alunos(char nomes[][TAMANHO_MAXIMO_NOME], int notas[], int total) {
    if(total == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    printf("======[ ALUNOS ]======\n");
    for(int pos = 0;pos < total;pos++) {
        printf("%d. %s - Nota: %d\n", (pos + 1), nomes[pos], notas[pos]);
    }
}

void salvar_arquivo(char nomes[][TAMANHO_MAXIMO_NOME], int notas[], int total) {
    FILE *arquivo = fopen("alunos.txt", "w");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for(int pos = 0;pos < total;pos++) {
        fprintf(arquivo, "%s;%d\n", nomes[pos], notas[pos]);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em 'alunos.txt'\n");
}

int carregar_arquivo(char nomes[][TAMANHO_MAXIMO_NOME], int notas[]) {
    FILE *arquivo = fopen("alunos.txt", "r");

    if(arquivo == NULL) {
        printf("Arquivo 'alunos.txt' não encontrado.\n");
    }

    int total = 0;
    while (fscanf(arquivo, "%49[^;];%d\n", nomes[total], &notas[total]) == 2)
    {
        total++;
        if (total >= MAXIMO_ALUNOS) break;
    }
    

    fclose(arquivo);
    printf("%d alunos carregados do arquivo.\n", total);
    return total;
}

int main() {
    char nomes[MAXIMO_ALUNOS][TAMANHO_MAXIMO_NOME];
    int notas[MAXIMO_ALUNOS];
    int total = 0;
    int opcao;
    do {
        opcao = menu();

        switch (opcao)
        {
            case 1:
                registrar_aluno(nomes, notas, &total);
                break;
            case 2:
                listar_alunos(nomes, notas, total);
                break;
            case 3:
                salvar_arquivo(nomes, notas, total);
                break;
            case 4:
                total = carregar_arquivo(nomes, notas);
                break;
            case 0:
                printf("Sair\n");
                break;
        }
    } while (opcao != 0);
    

    return 0;
}