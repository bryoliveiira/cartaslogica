#include <stdio.h>
#include <string.h>

struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    float densidade;
    float pibPerCapita;
};

void exibirMenu(int excluir) {
    printf("Escolha um atributo:\n");
    if (excluir != 1) printf("1. População\n");
    if (excluir != 2) printf("2. Área\n");
    if (excluir != 3) printf("3. PIB\n");
    if (excluir != 4) printf("4. Densidade Populacional\n");
    if (excluir != 5) printf("5. PIB per capita\n");
}

float obterValorAtributo(struct Carta c, int opcao) {
    switch(opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        case 5: return c.pibPerCapita;
        default: return 0;
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 215000000, 8515767, 1800000, 0, 0};
    struct Carta carta2 = {"Argentina", 47000000, 2780400, 500000, 0, 0};

    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int atributo1 = 0, atributo2 = 0;

    do {
        printf("\n--- Escolha o primeiro atributo para comparação ---\n");
        exibirMenu(0);
        printf("Opção: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida. Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    do {
        printf("\n--- Escolha o segundo atributo (diferente do primeiro) ---\n");
        exibirMenu(atributo1);
        printf("Opção: ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1)
            printf("Opção inválida. Tente novamente.\n");
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    float valor1_attr1 = obterValorAtributo(carta1, atributo1);
    float valor2_attr1 = obterValorAtributo(carta2, atributo1);

    float valor1_attr2 = obterValorAtributo(carta1, atributo2);
    float valor2_attr2 = obterValorAtributo(carta2, atributo2);

    int pontosCarta1 = 0;
    int pontosCarta2 = 0;

    if (atributo1 == 4) {
        (valor1_attr1 < valor2_attr1) ? pontosCarta1++ : (valor2_attr1 < valor1_attr1) ? pontosCarta2++ : 0;
    } else {
        (valor1_attr1 > valor2_attr1) ? pontosCarta1++ : (valor2_attr1 > valor1_attr1) ? pontosCarta2++ : 0;
    }

    if (atributo2 == 4) {
        (valor1_attr2 < valor2_attr2) ? pontosCarta1++ : (valor2_attr2 < valor1_attr2) ? pontosCarta2++ : 0;
    } else {
        (valor1_attr2 > valor2_attr2) ? pontosCarta1++ : (valor2_attr2 > valor1_attr2) ? pontosCarta2++ : 0;
    }

    float soma1 = (atributo1 == 4 ? -valor1_attr1 : valor1_attr1) + (atributo2 == 4 ? -valor1_attr2 : valor1_attr2);
    float soma2 = (atributo1 == 4 ? -valor2_attr1 : valor2_attr1) + (atributo2 == 4 ? -valor2_attr2 : valor2_attr2);

    printf("\n--- RESULTADO DA COMPARAÇÃO ---\n\n");

    char *nomesAtributos[6] = {"", "População", "Área", "PIB", "Densidade Populacional", "PIB per capita"};

    printf("%s - %s: %.2f\n", nomesAtributos[atributo1], carta1.nomePais, valor1_attr1);
    printf("%s - %s: %.2f\n", nomesAtributos[atributo1], carta2.nomePais, valor2_attr1);

    printf("%s - %s: %.2f\n", nomesAtributos[atributo2], carta1.nomePais, valor1_attr2);
    printf("%s - %s: %.2f\n", nomesAtributos[atributo2], carta2.nomePais, valor2_attr2);

    printf("\nSoma total de atributos:\n");
    printf("%s: %.2f\n", carta1.nomePais, soma1);
    printf("%s: %.2f\n", carta2.nomePais, soma2);

    if (soma1 > soma2)
        printf("\nResultado Final: %s venceu!\n", carta1.nomePais);
    else if (soma2 > soma1)
        printf("\nResultado Final: %s venceu!\n", carta2.nomePais);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}
