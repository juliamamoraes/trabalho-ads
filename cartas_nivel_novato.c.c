#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações de uma carta
typedef struct {
    char estado[3];
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

// Função para comparar duas cartas com base em um atributo específico
void compararCartas(Carta carta1, Carta carta2, int atributo) {
    printf("Comparação de cartas (Atributo: ");
    
    // Atributo escolhido (1: População, 2: Área, 3: PIB, 4: Densidade Populacional, 5: PIB per capita)
    if (atributo == 1) {
        printf("População):\n");
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
        
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 2) {
        printf("Área):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.area);
        
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.area < carta2.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 3) {
        printf("PIB):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib);
        
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.pib < carta2.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 4) {
        printf("Densidade Populacional):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.densidade_populacional);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.densidade_populacional);
        
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 5) {
        printf("PIB per capita):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);
        
        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.pib_per_capita < carta2.pib_per_capita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    // Definindo duas cartas com seus atributos
    Carta carta1 = {
        "SP", 
        "C001", 
        "São Paulo", 
        12300000, 
        1521.11, 
        693.8, 
        400, 
        0.0, 
        0.0
    };

    Carta carta2 = {
        "RJ", 
        "C002", 
        "Rio de Janeiro", 
        6000000, 
        1200.00, 
        365.5, 
        300, 
        0.0, 
        0.0
    };

    // Calculando a densidade populacional e o PIB per capita para as duas cartas
    calcularDensidadeEPibPerCapita(&carta1);
    calcularDensidadeEPibPerCapita(&carta2);
    
    // Atributo escolhido para comparação: 1 (População)
    int atributo_comparacao = 1;

    // Comparando as duas cartas com base no atributo escolhido
    compararCartas(carta1, carta2, atributo_comparacao);
    
    return 0;
}
