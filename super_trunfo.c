#include <stdio.h>

// Função para calcular o Super Poder de uma carta
float calcularSuperPoder(unsigned long int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional)
{
    float pibPerCapita = pib / populacao;
    return pib + populacao + area + pontosTuristicos + pibPerCapita + (1.0 / densidadePopulacional);
}

// Função auxiliar para exibir o menu (removendo uma opção já usada)
void exibirMenu(int ignorar)
{
    printf("\nEscolha um segundo atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++)
    {
        if (i == ignorar)
            continue;
        switch (i)
        {
        case 1:
            printf("%d - População\n", i);
            break;
        case 2:
            printf("%d - Área\n", i);
            break;
        case 3:
            printf("%d - PIB\n", i);
            break;
        case 4:
            printf("%d - Pontos Turísticos\n", i);
            break;
        case 5:
            printf("%d - Densidade Demográfica\n", i);
            break;
        }
    }
    printf("Digite sua opção: ");
}

// Função para obter o valor do atributo
float obterValor(int opcao, unsigned long pop, float area, float pib, int pontos, float densidade)
{
    switch (opcao)
    {
    case 1:
        return (float)pop;
    case 2:
        return area;
    case 3:
        return pib;
    case 4:
        return (float)pontos;
    case 5:
        return densidade;
    default:
        return 0.0;
    }
}

// Função para exibir o nome do atributo
const char *nomeAtributo(int opcao)
{
    switch (opcao)
    {
    case 1:
        return "População";
    case 2:
        return "Área";
    case 3:
        return "PIB";
    case 4:
        return "Pontos Turísticos";
    case 5:
        return "Densidade Demográfica";
    default:
        return "Desconhecido";
    }
}

int main()
{
    char estado1[3], estado2[3];
    char codigoCarta1[4], codigoCarta2[4];
    char nomeCidade1[20], nomeCidade2[20];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    // Entrada de dados
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

    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // Menu para escolha de dois atributos
    int atributo1, atributo2;
    printf("\n========== ESCOLHA DE ATRIBUTOS ==========\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    // Verifica se o primeiro é válido
    if (atributo1 < 1 || atributo1 > 5)
    {
        printf("Opção inválida!\n");
        return 1;
    }

    exibirMenu(atributo1);
    scanf("%d", &atributo2);

    // Verifica se o segundo é válido e diferente do primeiro
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1)
    {
        printf("Opção inválida!\n");
        return 1;
    }

    // Obter os valores dos atributos
    float valor1A = obterValor(atributo1, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float valor2A = obterValor(atributo1, populacao2, area2, pib2, pontosTuristicos2, densidade2);

    float valor1B = obterValor(atributo2, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float valor2B = obterValor(atributo2, populacao2, area2, pib2, pontosTuristicos2, densidade2);

    // Verifica vencedores individuais (usando operador ternário)
    int vencedorA = (atributo1 == 5) ? (valor1A < valor2A ? 1 : (valor1A > valor2A ? 2 : 0))
                                     : (valor1A > valor2A ? 1 : (valor1A < valor2A ? 2 : 0));
    int vencedorB = (atributo2 == 5) ? (valor1B < valor2B ? 1 : (valor1B > valor2B ? 2 : 0))
                                     : (valor1B > valor2B ? 1 : (valor1B < valor2B ? 2 : 0));

    // Soma total dos atributos
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    int vencedorFinal = (soma1 > soma2) ? 1 : (soma2 > soma1 ? 2 : 0);

    // Resultado
    printf("\n========== RESULTADO ==========\n");
    printf("Carta 1 - %s (%s)\n", nomeCidade1, estado1);
    printf("%s: %.2f | %s: %.2f | Soma: %.2f\n", nomeAtributo(atributo1), valor1A, nomeAtributo(atributo2), valor1B, soma1);

    printf("\nCarta 2 - %s (%s)\n", nomeCidade2, estado2);
    printf("%s: %.2f | %s: %.2f | Soma: %.2f\n", nomeAtributo(atributo1), valor2A, nomeAtributo(atributo2), valor2B, soma2);

    // Resultado final
    if (vencedorFinal == 1)
        printf("\nVENCEDORA: %s\n", nomeCidade1);
    else if (vencedorFinal == 2)
        printf("\nVENCEDORA: %s\n", nomeCidade2);
    else
        printf("\nEMPATE!\n");

    return 0;
}
