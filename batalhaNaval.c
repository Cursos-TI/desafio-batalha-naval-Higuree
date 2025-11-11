#include <stdio.h>

int main() {
    // Tamanho fixo do tabuleiro (10x10)
    int tabuleiro[10][10];

    // Tamanho fixo dos navios
    const int tamanho_navio = 3;

    // Coordenadas iniciais dos navios
    int linha_navio_horizontal = 2; // começa na linha 2
    int coluna_navio_horizontal = 4; // começa na coluna 4

    int linha_navio_vertical = 5; // começa na linha 5
    int coluna_navio_vertical = 1; // começa na coluna 1

    // 1️⃣ Inicializando o tabuleiro com 0 (representa água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Posicionando o navio horizontal
    // Verifica se o navio cabe no tabuleiro
    if (coluna_navio_horizontal + tamanho_navio <= 10) {
        for (int j = 0; j < tamanho_navio; j++) {
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] = 3;
        }
    } else {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
        return 1;
    }

    // 3️⃣ Posicionando o navio vertical
    // Verifica se o navio cabe e não se sobrepõe
    if (linha_navio_vertical + tamanho_navio <= 10) {
        int sobreposicao = 0;
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
            }
        } else {
            printf("Erro: Navio vertical se sobrepõe ao navio horizontal!\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
        return 1;
    }

    // 4️⃣ Exibindo o tabuleiro
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    printf("   "); // Espaço para cabeçalho de colunas
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d  ", i); // Número da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}