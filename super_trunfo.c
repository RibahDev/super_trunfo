#include <stdio.h>

// Função para calcular o Super Poder de uma carta
float calcularSuperPoder(unsigned long int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional)
{
    float pibPerCapita = pib / populacao;
    return pib + populacao + area + pontosTuristicos + pibPerCapita + (1.0 / densidadePopulacional); // Soma com a inversão da densidade
}

int main()
{
    // Definição das variáveis para as duas cartas
    char estado1[3], estado2[3];
    char codigoCarta1[4], codigoCarta2[4];
    char nomeCidade1[20], nomeCidade2[20];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    // Entrada dos dados da Carta 1
    printf("Digite o estado da Carta 1 (ex: SP): ");
    scanf("%2s", estado1);

    printf("Digite o código da Carta 1 (ex: j01): ");
    scanf("%3s", codigoCarta1);

    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %[^\n]", nomeCidade1); // Lê a cidade com espaços

    printf("População da Carta 1: ");
    scanf("%lu", &populacao1);

    printf("Área em Km² da Carta 1: ");
    scanf("%f", &area1);

    printf("PIB da Carta 1: ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada dos dados da Carta 2
    printf("\nDigite o estado da Carta 2 (ex: GO): ");
    scanf("%2s", estado2);

    printf("Digite o código da Carta 2 (ex: g02): ");
    scanf("%3s", codigoCarta2);

    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %[^\n]", nomeCidade2); // Lê a cidade com espaços

    printf("População da Carta 2: ");
    scanf("%lu", &populacao2);

    printf("Área em Km² da Carta 2: ");
    scanf("%f", &area2);

    printf("PIB da Carta 2: ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo dos atributos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = pib1 / populacao1;
    float pibPerCapita2 = pib2 / populacao2;

    // Cálculo do Super Poder de cada carta
    float superPoder1 = calcularSuperPoder(populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float superPoder2 = calcularSuperPoder(populacao2, area2, pib2, pontosTuristicos2, densidade2);

    // Exibição das cartas
    printf("\n========== CARTAS CADASTRADAS ==========\n");

    printf("\nCARTA 1 - Estado: %s | Código: %s | Cidade: %s\n", estado1, codigoCarta1, nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f Km²\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f habitantes/Km²\n", densidade1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCARTA 2 - Estado: %s | Código: %s | Cidade: %s\n", estado2, codigoCarta2, nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f Km²\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f habitantes/Km²\n", densidade2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Comparação dos atributos
    printf("\n========== COMPARAÇÃO DAS CARTAS ==========\n");

    // Comparando os atributos um a um e exibindo quem venceu
    printf("População: Carta 1 (%d) | Carta 2 (%d)\n", populacao1 > populacao2, populacao2 >= populacao1);
    printf("Área: Carta 1 (%d) | Carta 2 (%d)\n", area1 > area2, area2 >= area1);
    printf("PIB: Carta 1 (%d) | Carta 2 (%d)\n", pib1 > pib2, pib2 >= pib1);
    printf("Pontos Turísticos: Carta 1 (%d) | Carta 2 (%d)\n", pontosTuristicos1 > pontosTuristicos2, pontosTuristicos2 >= pontosTuristicos1);
    printf("Densidade Populacional: Carta 1 %d | Carta 2 (%d)\n", densidade1 < densidade2, densidade2 <= densidade1); // Menor densidade vence
    printf("PIB per Capita: Carta 1 (%d) | Carta 2 (%d)\n", pibPerCapita1 > pibPerCapita2, pibPerCapita2 >= pibPerCapita1);
    printf("Super Poder: Carta 1 (%d) | Carta 2 (%d)\n", superPoder1 > superPoder2, superPoder2 >= superPoder1);

    return 0;
}
