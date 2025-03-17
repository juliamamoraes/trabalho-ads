#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 100

// Estrutura da carta
typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float pib;
    float area;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Calcula densidade e PIB per capita
void calcularDados(Carta *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;

    if (carta->populacao > 0)
        carta->pibPerCapita = carta->pib / carta->populacao;
    else
        carta->pibPerCapita = 0;
}

// Cadastra uma nova carta
int cadastrarCarta(Carta cartas[], int total) {
    if (total >= MAX_CARTAS) {
        printf("Limite de cartas atingido!\n");
        return total;
    }

    Carta nova;

    printf("Estado: ");
    scanf(" %[^\n]", nova.estado);

    printf("Código da cidade: ");
    scanf("%d", &nova.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nova.nome);

    printf("População: ");
    scanf("%d", &nova.populacao);

    printf("PIB (em milhões): ");
    scanf("%f", &nova.pib);

    printf("Área (km²): ");
    scanf("%f", &nova.area);

    printf("Número de pontos turísticos: ");
    scanf("%d", &nova.pontosTuristicos);

    calcularDados(&nova);

    cartas[total] = nova;
    return total + 1;
}

// Exibe todas as cartas
void exibirCartas(Carta cartas[], int total) {
    if (total == 0) {
        printf("Nenhuma carta cadastrada ainda.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\n--- Carta %d ---\n", i + 1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Código: %d\n", cartas[i].codigo);
        printf("Cidade: %s\n", cartas[i].nome);
        printf("População: %d\n", cartas[i].populacao);
        printf("PIB: %.2f milhões\n", cartas[i].pib);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("Pontos turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].densidadePopulacional);
        printf("PIB per capita: %.2f\n", cartas[i].pibPerCapita);
    }
}

// SALVAR as cartas em um arquivo texto
void salvarCartasEmArquivo(Carta cartas[], int total) {
    FILE *arquivo = fopen("cartas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "Carta %d:\n", i + 1);
        fprintf(arquivo, "Estado: %s\n", cartas[i].estado);
        fprintf(arquivo, "Código: %d\n", cartas[i].codigo);
        fprintf(arquivo, "Cidade: %s\n", cartas[i].nome);
        fprintf(arquivo, "População: %d\n", cartas[i].populacao);
        fprintf(arquivo, "PIB: %.2f\n", cartas[i].pib);
        fprintf(arquivo, "Área: %.2f\n", cartas[i].area);
        fprintf(arquivo, "Pontos turísticos: %d\n", cartas[i].pontosTuristicos);
        fprintf(arquivo, "Densidade Populacional: %.2f\n", cartas[i].densidadePopulacional);
        fprintf(arquivo, "PIB per capita: %.2f\n", cartas[i].pibPerCapita);
        fprintf(arquivo, "-----------------------------\n");
    }

    fclose(arquivo);
    printf("Cartas salvas com sucesso no arquivo 'cartas.txt'!\n");
}

// Função principal com o menu
int main() {
    Carta cartas[MAX_CARTAS];
    int totalCartas = 0;
    int opcao;

    do {
        printf("\n=== Super Trunfo: Cadastro de Cartas ===\n");
        printf("1. Cadastrar nova carta\n");
        printf("2. Exibir todas as cartas\n");
        printf("3. Salvar cartas em arquivo\n"); // <-- nova opção
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                totalCartas = cadastrarCarta(cartas, totalCartas);
                break;
            case 2:
                exibirCartas(cartas, totalCartas);
                break;
            case 3:
                salvarCartasEmArquivo(cartas, totalCartas);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
#include <stdio.h>

// Função para salvar cartas no arquivo cartas.txt
void salvarCartasEmArquivo(Carta cartas[], int total) {
    FILE *arquivo = fopen("cartas.txt", "w"); // "w" = write (escrever)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "Carta %d:\n", i + 1);
        fprintf(arquivo, "Estado: %s\n", cartas[i].estado);
        fprintf(arquivo, "Código: %d\n", cartas[i].codigo);
        fprintf(arquivo, "Cidade: %s\n", cartas[i].nome);
        fprintf(arquivo, "População: %d\n", cartas[i].populacao);
        fprintf(arquivo, "PIB: %.2f\n", cartas[i].pib);
        fprintf(arquivo, "Área: %.2f\n", cartas[i].area);
        fprintf(arquivo, "Pontos turísticos: %d\n", cartas[i].pontosTuristicos);
        fprintf(arquivo, "Densidade Populacional: %.2f\n", cartas[i].densidadePopulacional);
        fprintf(arquivo, "PIB per capita: %.2f\n", cartas[i].pibPerCapita);
        fprintf(arquivo, "-------------------------\n");
    }

    fclose(arquivo); // Fecha o arquivo
    printf("Cartas salvas com sucesso no arquivo 'cartas.txt'!\n");
}
