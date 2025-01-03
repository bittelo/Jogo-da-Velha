#include <stdio.h>
#define PX 'X'
#define PO 'O'
#define qtdlinhas 3
#define qtdcolunas 3
#define charp '_'
#define empate 'E'

int main() {
    int linha, coluna, posicao;
    int cont = 0;
    char tabuleiro[qtdlinhas][qtdcolunas];
    char atual = PX;
    char ganhador = empate;

    for (linha = 0; linha < qtdlinhas; linha++) {
        for (coluna = 0; coluna < qtdcolunas; coluna++) {
            tabuleiro[linha][coluna] = charp;
        }
    }

    while (1) {
        printf("\nTabuleiro atual:\n");
        for (linha = 0; linha < qtdlinhas; linha++) {
            for (coluna = 0; coluna < qtdcolunas; coluna++) {
                printf("%c ", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }

        printf("\nJogador %c, faça sua jogada (1-9):\n", atual);
        scanf("%d", &posicao);

        if (posicao < 1 || posicao > 9) {
            printf("Posição inválida! Escolha um número entre 1 e 9.\n");
            continue;
        }

        linha = (posicao - 1) / qtdcolunas;
        coluna = (posicao - 1) % qtdcolunas;

        if (tabuleiro[linha][coluna] != charp) {
            printf("Essa posição já foi preenchida, escolha outra.\n");
            continue;
        }

        tabuleiro[linha][coluna] = atual;

        for (linha = 0; linha < qtdlinhas; linha++) {
            if (tabuleiro[linha][0] == atual && tabuleiro[linha][1] == atual && tabuleiro[linha][2] == atual) {
                ganhador = atual;
                break;
            }
        }

        for (coluna = 0; coluna < qtdcolunas; coluna++) {
            if (tabuleiro[0][coluna] == atual && tabuleiro[1][coluna] == atual && tabuleiro[2][coluna] == atual) {
                ganhador = atual;
                break;
            }
        }

        if (tabuleiro[0][0] == atual && tabuleiro[1][1] == atual && tabuleiro[2][2] == atual) {
            ganhador = atual;
            break;
        }

        if (tabuleiro[0][2] == atual && tabuleiro[1][1] == atual && tabuleiro[2][0] == atual) {
            ganhador = atual;
            break;
        }

        cont++;
        if (cont == 9) {
            break;
        }

        atual = (atual == PX) ? PO : PX;
    }

    printf("\nFim do jogo!\n");
    if (ganhador == empate) {
        printf("O jogo terminou em empate.\n");
    } else {
        printf("O jogador %c venceu!\n", ganhador);
    }

    return 0;
}
