#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações de uma carta
typedef struct {
    char nome[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcularDensidadeEPibPerCapita(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar as duas cartas com base no atributo selecionado
void compararCartas(Carta carta1, Carta carta2, int atributo) {
    switch (atributo) {
        case 1: // População
            printf("Comparação de cartas (Atributo: População):\n");
            printf("Carta 1 - %s: %d\n", carta1.cidade, carta1.populacao);
            printf("Carta 2 - %s: %d\n", carta2.cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2: // Área
            printf("Comparação de cartas (Atributo: Área):\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.cidade, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta1.area < carta2.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3: // PIB
            printf("Comparação de cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s: %.2f bilhões\n", carta1.cidade, carta1.pib);
            printf("Carta 2 - %s: %.2f bilhões\n", carta2.cidade, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta1.pib < carta2.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4: // Número de pontos turísticos
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n");
            printf("Carta 1 - %s: %d\n", carta1.cidade, carta1.pontos_turisticos);
            printf("Carta 2 - %s: %d\n", carta2.cidade, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5: // Densidade Populacional
            printf("Comparação de cartas (Atributo: Densidade Populacional):\n");
            printf("Carta 1 - %s: %.2f habitantes/km²\n", carta1.cidade, carta1.densidade_populacional);
            printf("Carta 2 - %s: %.2f habitantes/km²\n", carta2.cidade, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida.\n");
    }
}

int main() {
    // Definindo duas cartas
    Carta carta1 = {
        "Brasil",
        "C001",
        "São Paulo",
        12300000, // População
        1521.11,   // Área
        693.8,     // PIB
        400,       // Pontos turísticos
        0.0,       // Densidade populacional
        0.0        // PIB per capita
    };
    
    Carta carta2 = {
        "Brasil",
        "C002",
        "Rio de Janeiro",
        6000000,   // População
        1200.00,   // Área
        365.5,     // PIB
        300,       // Pontos turísticos
        0.0,       // Densidade populacional
        0.0        // PIB per capita
    };

    // Calculando a densidade populacional e PIB per capita para as duas cartas
    calcularDensidadeEPibPerCapita(&carta1);
    calcularDensidadeEPibPerCapita(&carta2);

    // Menu interativo
    int atributo;
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Digite a opção (1-5): ");
    scanf("%d", &atributo);

    // Comparando as cartas com base na escolha do jogador
    compararCartas(carta1, carta2, atributo);

    return 0;
}
