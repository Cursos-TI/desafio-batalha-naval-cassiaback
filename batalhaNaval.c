#include <stdio.h>

int main() {
    
    // Batalha Naval - Nivel Novato
    // Tabuleiro 10x10 com 2 navios de tamanho 3

    // 1. Representar o Tabuleiro (matriz 10x10 inicializada com 0)
    int tabuleiro[10][10] = {0};

    // 2. Representar o Navio (vetor unidimensional de tamanho 3)
    int navio[3] = {3, 3, 3}; 

    // Coordenadas iniciais do Navio Horizontal (linha, coluna)
    int linhaH = 2, colH = 2;

    // Coordenadas iniciais do Navio Vertical (linha, coluna)
    int linhaV = 5, colV = 7;

    // Flag para verificar se as posições são válidas
    int posicoes_validas = 1;


    // VALIDAÇÃO DE LIMITES DO TABULEIRO

    if (colH + 3 > 10 || linhaV + 3 > 10) {
        posicoes_validas = 0;
        printf("Erro: Navio fora dos limites do tabuleiro!\n");
    }


    // POSICIONAMENTO E VALIDAÇÃO DE SOBREPOSIÇÃO

    if (posicoes_validas == 1) {
        
        // 1. Coloca o navio Horizontal primeiro
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colH + i] = navio[i];
        }

        // 2. Testa se o espaço do navio Vertical está livre (sem sobreposição)
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colV] == 3) {
                posicoes_validas = 0;
                printf("Erro: Sobreposição de navios detectada!\n");
                break; 
            }
        }

        // 3. Se estiver tudo livre, coloca o navio Vertical
        if (posicoes_validas == 1) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaV + i][colV] = navio[i];
            }
        }

        // EXIBIÇÃO DAS COORDENADAS DOS NAVIOS

        if (posicoes_validas == 1) {
            printf("=== Coordenadas dos Navios ===\n");

            printf("Navio Horizontal:\n");
            for (int i = 0; i < 3; i++) {
                printf("Parte %d: (%d, %d)\n", i + 1, linhaH, colH + i);
            }

            printf("\nNavio Vertical:\n");
            for (int i = 0; i < 3; i++) {
                printf("Parte %d: (%d, %d)\n", i + 1, linhaV + i, colV);
            }

            // EXIBIÇÃO DO TABULEIRO COMPLETO

            printf("\n=== Tabuleiro de Batalha Naval ===\n");
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
