#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[30];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    struct Carta carta1, carta2;

    strcpy(carta1.estado, "São Paulo");
    strcpy(carta1.codigo, "SP01");
    strcpy(carta1.nome, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 2300000.0;
    carta1.pontosTuristicos = 120;

    strcpy(carta2.estado, "Rio de Janeiro");
    strcpy(carta2.codigo, "RJ01");
    strcpy(carta2.nome, "Rio de Janeiro");
    carta2.populacao = 6000000;
    carta2.area = 1182.3;
    carta2.pib = 360000.0;
    carta2.pontosTuristicos = 90;

    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    printf("Comparação de cartas (Atributo: PIB per Capita):\n\n");

    printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nome, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): R$ %.2f\n\n", carta2.nome, carta2.estado, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate! As duas cartas têm o mesmo PIB per capita.\n");
    }

    return 0;
}
