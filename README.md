Super Trunfo de Cidades (C)
Este programa simula uma partida de Super Trunfo entre duas cartas que representam cidades brasileiras. Cada carta possui atributos como população, área, PIB, pontos turísticos e densidade demográfica. O jogador escolhe qual atributo será comparado e o programa determina a cidade vencedora com base nesse critério.

✅ Funcionalidades
Entrada interativa para cadastrar 2 cartas de cidades.

Cálculo do "Super Poder" de cada carta (valor somado dos atributos).

Menu interativo para escolher o atributo de comparação:

População

Área

PIB

Pontos Turísticos

Densidade Demográfica (MENOR valor vence)

Exibição de informações completas e comparação com resultado.

🚀 Como executar
Compile o código:

bash
Copiar
Editar
gcc -o supertrunfo supertrunfo.c
Execute o programa:

bash
Copiar
Editar
./supertrunfo
Siga as instruções no terminal para cadastrar duas cidades e escolher qual atributo deseja comparar.

📥 Exemplo de uso
yaml
Copiar
Editar
Digite o estado da Carta 1 (ex: SP): SP
Digite o código da Carta 1 (ex: j01): j01
Digite o nome da cidade da Carta 1: São Paulo
População da Carta 1: 12300000
Área em Km² da Carta 1: 1521.11
PIB da Carta 1: 700000000
Número de pontos turísticos da Carta 1: 10

...

Escolha o atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua opção: 1

Comparando População:
São Paulo: 12300000 habitantes
Goiânia: 1500000 habitantes
Vencedor: São Paulo
🛠️ Requisitos
Compilador C (como gcc)

Terminal ou console

📌 Observações
A densidade demográfica é calculada automaticamente com base na população e área.

No caso de empate entre atributos, o programa informará.

O "Super Poder" é exibido apenas como curiosidade e não interfere na lógica de vitória.
