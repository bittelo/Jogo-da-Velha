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
    char atual =PX;
    char ganhador = empate; 

   
    for (linha = 0; linha < qtdlinhas; linha++) {
        for (coluna = 0; coluna < qtdcolunas; coluna++) {
            tabuleiro[linha][coluna] = charp;
        }
    }

    while (1) {
        printf("\n\n%d\n\n", cont);
        printf("\nTabuleiro atual:\n");
        for (linha = 0; linha < qtdlinhas; linha++) {
            for (coluna = 0; coluna < qtdcolunas; coluna++) {
                printf("%c ", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }

        
        printf("\nJogador %c, faça sua jogada (1-9):\n",atual);
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


        for(linha = 0; linha < qtdlinhas; linha +=1){
            if(tabuleiro[linha][0] == PX && tabuleiro [linha][1] == PX && tabuleiro [linha][2] == PX){
            ganhador == PX;
                break;
        }
        
    }

        for(coluna = 0; coluna < qtdcolunas; coluna +=1){
            if(tabuleiro[0][coluna] == PX && tabuleiro [0][coluna] == PX && tabuleiro [0][coluna] == PX){
                ganhador == PX;
                    break;
            
            }   
        }
        
        if(tabuleiro[0][0] == PX && tabuleiro [1][1] == PX && tabuleiro [2][2] == PX){
            ganhador == PX;
            break;
        }

        if(tabuleiro[0][2] == PX && tabuleiro [1][1] == PX && tabuleiro [2][0] == PX){
            ganhador == PX;
            break;
        }
        
        
        
        tabuleiro[linha][coluna] = atual;

        cont += 1;
            
        if (cont % 2 == 0){
            atual = PX;
        } else {
            atual = PO;
        }


        
        }

    return 0;

    
}
