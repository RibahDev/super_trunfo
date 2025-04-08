#include <stdio.h>

// Função para calcular o Super Poder de uma carta
float calcularSuperPoder(unsigned long int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional)
{
    float pibPerCapita = pib / populacao;
    return pib + populacao + area + pontosTuristicos + pibPerCapita + (1.0 / densidadePopulacional); // Soma com a inversão da densidade
}

int main()
{
    // Declaração de variáveis
    char estado1[3], estado2[3];
    char codigoCarta1[4], codigoCarta2[4];
    char nomeCidade1[20], nomeCidade2[20];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    // Entrada das cartas
    printf("Digite o estado da Carta 1 (ex: SP): ");
    scanf("%2s", estado1);
    printf("Digite o código da Carta 1 (ex: j01): ");
    scanf("%3s", codigoCarta1);
    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População da Carta 1: ");
    scanf("%lu", &populacao1);
    printf("Área em Km² da Carta 1: ");
    scanf("%f", &area1);
    printf("PIB da Carta 1: ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    printf("\nDigite o estado da Carta 2 (ex: GO): ");
    scanf("%2s", estado2);
    printf("Digite o código da Carta 2 (ex: g02): ");
    scanf("%3s", codigoCarta2);
    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População da Carta 2: ");
    scanf("%lu", &populacao2);
    printf("Área em Km² da Carta 2: ");
    scanf("%f", &area2);
    printf("PIB da Carta 2: ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = pib1 / populacao1;
    float pibPerCapita2 = pib2 / populacao2;
    float superPoder1 = calcularSuperPoder(populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float superPoder2 = calcularSuperPoder(populacao2, area2, pib2, pontosTuristicos2, densidade2);

    // Exibir informações
    printf("\n========== CARTAS CADASTRADAS ==========\n");
    printf("\nCARTA 1 - %s (%s):\nPopulação: %lu\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per capita: %.2f\nSuper Poder: %.2f\n",
           nomeCidade1, estado1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1, superPoder1);
    printf("\nCARTA 2 - %s (%s):\nPopulação: %lu\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per capita: %.2f\nSuper Poder: %.2f\n",
           nomeCidade2, estado2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2, superPoder2);

    // Menu interativo
    int opcao;
    printf("\n========== MENU DE COMPARAÇÃO ==========\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n========== RESULTADO DA COMPARAÇÃO ==========\n");
    switch (opcao)
    {
    case 1:
        printf("Comparando População:\n");
        printf("%s: %lu habitantes\n", nomeCidade1, populacao1);
        printf("%s: %lu habitantes\n", nomeCidade2, populacao2);
        if (populacao1 > populacao2)
            printf("Vencedor: %s\n", nomeCidade1);
        else if (populacao2 > populacao1)
            printf("Vencedor: %s\n", nomeCidade2);
        else
            printf("Empate!\n");
        break;

    case 2:
        printf("Comparando Área:\n");
        printf("%s: %.2f km²\n", nomeCidade1, area1);
        printf("%s: %.2f km²\n", nomeCidade2, area2);
        if (area1 > area2)
            printf("Vencedor: %s\n", nomeCidade1);
        else if (area2 > area1)
            printf("Vencedor: %s\n", nomeCidade2);
        else
            printf("Empate!\n");
        break;

    case 3:
        printf("Comparando PIB:\n");
        printf("%s: %.2f\n", nomeCidade1, pib1);
        printf("%s: %.2f\n", nomeCidade2, pib2);
        if (pib1 > pib2)
            printf("Vencedor: %s\n", nomeCidade1);
        else if (pib2 > pib1)
            printf("Vencedor: %s\n", nomeCidade2);
        else
            printf("Empate!\n");
        break;

    case 4:
        printf("Comparando Pontos Turísticos:\n");
        printf("%s: %d\n", nomeCidade1, pontosTuristicos1);
        printf("%s: %d\n", nomeCidade2, pontosTuristicos2);
        if (pontosTuristicos1 > pontosTuristicos2)
            printf("Vencedor: %s\n", nomeCidade1);
        else if (pontosTuristicos2 > pontosTuristicos1)
            printf("Vencedor: %s\n", nomeCidade2);
        else
            printf("Empate!\n");
        break;

    case 5:
        printf("Comparando Densidade Demográfica (MENOR valor vence):\n");
        printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
        printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);
        if (densidade1 < densidade2)
            printf("Vencedor: %s\n", nomeCidade1);
        else if (densidade2 < densidade1)
            printf("Vencedor: %s\n", nomeCidade2);
        else
            printf("Empate!\n");
        break;

    default:
        printf("Opção inválida! Tente novamente.\n");
        break;
    }

    return 0;
}
