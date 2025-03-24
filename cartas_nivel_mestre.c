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

// Função para comparar as cartas com base no atributo escolhido
float compararAtributo(Carta carta1, Carta carta2, int atributo) {
    float resultado1 = 0, resultado2 = 0;

    switch (atributo) {
        case 1: // População
            resultado1 = carta1.populacao;
            resultado2 = carta2.populacao;
            break;
        case 2: // Área
            resultado1 = carta1.area;
            resultado2 = carta2.area;
            break;
        case 3: // PIB
            resultado1 = carta1.pib;
            resultado2 = carta2.pib;
            break;
        case 4: // Pontos Turísticos
            resultado1 = carta1.pontos_turisticos;
            resultado2 = carta2.pontos_turisticos;
            break;
        case 5: // Densidade Populacional
            resultado1 = carta1.densidade_populacional;
            resultado2 = carta2.densidade_populacional;
            break;
        default:
            printf("Opção inválida.\n");
            return -1; // Erro
    }

    // Se for densidade populacional, menor valor vence
    if (atributo == 5) {
        return (resultado1 < resultado2) ? resultado1 : resultado2; // Menor vence
    }

    // Para os outros atributos, maior valor vence
    return (resultado1 > resultado2) ? resultado1 : resultado2;
}

// Função para somar os atributos comparados de ambas as cartas
float somaAtributos(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    float resultado1 = compararAtributo(carta1, carta2, atributo1) + compararAtributo(carta1, carta2, atributo2);
    return resultado1;
}

// Função para comparar as cartas com base na soma dos atributos
void compararCartas(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    // Comparar os dois atributos
    float resultado1 = somaAtributos(carta1, carta2, atributo1, atributo2);
    float resultado2 = somaAtributos(carta2, carta1, atributo1, atributo2);

    printf("\nComparação entre as cartas:\n");
    printf("Carta 1 - %s (%s):\n", carta1.cidade, carta1.codigo);
    printf("  Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", 
           compararAtributo(carta1, carta2, atributo1),
           compararAtributo(carta1, carta2, atributo2),
           resultado1);
    
    printf("Carta 2 - %s (%s):\n", carta2.cidade, carta2.codigo);
    printf("  Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", 
           compararAtributo(carta2, carta1, atributo1),
           compararAtributo(carta2, carta1, atributo2),
           resultado2);

    // Determinar o vencedor com base na soma dos atributos
    if (resultado1 > resultado2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (resultado1 < resultado2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }
}

// Função para exibir o menu e receber a escolha do jogador
void exibirMenu() {
    printf("\nEscolha os dois atributos para comparar as cartas:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
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

    // Exibindo o menu e recebendo os atributos escolhidos pelo jogador
    int atributo1, atributo2;
    exibirMenu();
    printf("Escolha o primeiro atributo (1-5): ");
    scanf("%d", &atributo1);
    printf("Escolha o segundo atributo (1-5): ");
    scanf("%d", &atributo2);

    // Verificando se os atributos são diferentes
    if (atributo1 == atributo2) {
        printf("Erro: Você não pode escolher o mesmo atributo duas vezes!\n");
        return 1; // Encerra o programa devido ao erro
    }

    // Comparando as cartas com base nos atributos escolhidos
    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}
