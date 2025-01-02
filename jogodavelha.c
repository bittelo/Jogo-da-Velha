#include <stdio.h>
#define PX 'X'
#define PO 'O'
#define qtdlinhas 3
#define qtdcolunas 3
#define charp '_'

int main() {
    int linha, coluna, posicao;
    char tabuleiro[qtdlinhas][qtdcolunas];

   
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

        
        printf("\nJogador %c, faça sua jogada (1-9):\n", PX);
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

        
        tabuleiro[linha][coluna] = PX;

        
    }

    return 0;
}
