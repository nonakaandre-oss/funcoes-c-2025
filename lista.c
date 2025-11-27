  #include <stdio.h>

#define MAX_TAREFAS 100
#define TAM_DESC 200

typedef struct {
    char descricao[TAM_DESC];
    int concluida;   // 0 = pendente, 1 = concluída
} Tarefa;


/* -----------------------------------------------------
   Função auxiliar: ler linha sem usar string.h
   Remove o '\n' manualmente.
----------------------------------------------------- */
void lerLinha(char *str, int tam) {
    fgets(str, tam, stdin);

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}


/* -----------------------------------------------------
   Carregar arquivo tarefas.txt manualmente
   Formato da linha no arquivo:

      0|descricao da tarefa
----------------------------------------------------- */
void carregarArquivo(Tarefa lista[], int *total) {
    FILE *arq = fopen("tarefas.txt", "r");
    if (!arq) {
        printf("Nenhum arquivo encontrado. Lista iniciada vazia.\n");
        *total = 0;
        return;
    }

    *total = 0;
    char linha[300];

    while (fgets(linha, sizeof(linha), arq) != NULL) {

        int i = 0;

        // Lê status (0 ou 1) — o primeiro caractere antes do '|'
        lista[*total].concluida = linha[0] - '0';

        // Pular "X|" (2 caracteres)
        i = 2;

        // Copiar descrição manualmente
        int j = 0;
        while (linha[i] != '\0' && linha[i] != '\n') {
            lista[*total].descricao[j] = linha[i];
            i++;
            j++;
        }
        lista[*total].descricao[j] = '\0';

        (*total)++;
    }

    fclose(arq);
}


/* -----------------------------------------------------
   Salvar tarefas no arquivo
----------------------------------------------------- */
void salvarArquivo(Tarefa lista[], int total) {
    FILE *arq = fopen("tarefas.txt", "w");
    if (!arq) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arq, "%d|%s\n", lista[i].concluida, lista[i].descricao);
    }

    fclose(arq);
}


/* -----------------------------------------------------
   Adicionar tarefa
----------------------------------------------------- */
void adicionarTarefa(Tarefa lista[], int *total) {
    if (*total >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido.\n");
        return;
    }

    printf("Digite a descrição da tarefa:\n");
    lerLinha(lista[*total].descricao, TAM_DESC);

    lista[*total].concluida = 0;

    (*total)++;

    salvarArquivo(lista, *total);

    printf("Tarefa adicionada!\n");
}


/* -----------------------------------------------------
   Listar todas
----------------------------------------------------- */
void listarTodas(Tarefa lista[], int total) {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%d. [%s] %s\n",
               i + 1,
               lista[i].concluida ? "Concluída" : "Pendente",
               lista[i].descricao);
    }
}


/* -----------------------------------------------------
   Listar pendentes
----------------------------------------------------- */
void listarPendentes(Tarefa lista[], int total) {
    int achou = 0;

    for (int i = 0; i < total; i++) {
        if (!lista[i].concluida) {
            printf("%d. [Pendente] %s\n", i + 1, lista[i].descricao);
            achou = 1;
        }
    }

    if (!achou) {
        printf("Nenhuma tarefa pendente.\n");
    }
}


/* -----------------------------------------------------
   Marcar como concluída
----------------------------------------------------- */
void marcarConcluida(Tarefa lista[], int total) {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    listarTodas(lista, total);

    int num;
    printf("Digite o número da tarefa: ");
    scanf("%d", &num);
    getchar(); // limpa buffer

    if (num < 1 || num > total) {
        printf("Número inválido.\n");
        return;
    }

    lista[num - 1].concluida = 1;

    salvarArquivo(lista, total);

    printf("Tarefa marcada como concluída!\n");
}


/* -----------------------------------------------------
   Programa Principal
----------------------------------------------------- */
int main() {
    Tarefa lista[MAX_TAREFAS];
    int total = 0;
    int opcao;

    carregarArquivo(lista, &total);

    do {
        printf("\n --- LISTA DE TAREFAS ---\n");
        printf("[1] Adicionar Nova Tarefa\n");
        printf("[2] Listar TODAS as Tarefas\n");
        printf("[3] Listar Tarefas PENDENTES\n");
        printf("[4] Marcar Tarefa como Concluída\n");
        printf("[0] Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);
        getchar(); // consome \n

        if (opcao == 1) adicionarTarefa(lista, &total);
        else if (opcao == 2) listarTodas(lista, total);
        else if (opcao == 3) listarPendentes(lista, total);
        else if (opcao == 4) marcarConcluida(lista, total);
        else if (opcao != 0) printf("Opção inválida.\n");

    } while (opcao != 0);

    return 0;
}
