#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas definidas (corrigidas para evitar sobreposição)
    // Navio horizontal: linha 2, coluna 1 -> (2,1),(2,2),(2,3)
    int linha_navio_h = 2, coluna_navio_h = 1;

    // Navio vertical: linha 4, coluna 5 -> (4,5),(5,5),(6,5)
    int linha_navio_v = 4, coluna_navio_v = 5;

    // Navio diagonal ↘ corrigido: começa em (0,7) -> (0,7),(1,8),(2,9)
    int linha_navio_diag1 = 0, coluna_navio_diag1 = 7;

    // Navio diagonal ↙: começa em (6,8) -> (6,8),(7,7),(8,6)
    int linha_navio_diag2 = 6, coluna_navio_diag2 = 8;

    int sobreposicao = 0;

    #define CELULA_OCUPADA(l, c) (tabuleiro[l][c] == NAVIO)

    // Posicionar navio horizontal
    if (coluna_navio_h + TAM_NAVIO <= TAM) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            if (CELULA_OCUPADA(linha_navio_h, coluna_navio_h + j)) {
                sobreposicao = 1;
            }
        }
        if (!sobreposicao) {
            for (int j = 0; j < TAM_NAVIO; j++)
                tabuleiro[linha_navio_h][coluna_navio_h + j] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio horizontal!\n");
            return 1;
        }
    } else {
        printf("Erro: navio horizontal nao cabe no tabuleiro!\n");
        return 1;
    }

    // Posicionar navio vertical
    sobreposicao = 0;
    if (linha_navio_v + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (CELULA_OCUPADA(linha_navio_v + i, coluna_navio_v)) {
                sobreposicao = 1;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linha_navio_v + i][coluna_navio_v] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio vertical!\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical nao cabe no tabuleiro!\n");
        return 1;
    }

    // Posicionar navio diagonal ↘ (linha e coluna aumentam)
    sobreposicao = 0;
    if (linha_navio_diag1 + TAM_NAVIO <= TAM && coluna_navio_diag1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (CELULA_OCUPADA(linha_navio_diag1 + i, coluna_navio_diag1 + i)) {
                sobreposicao = 1;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linha_navio_diag1 + i][coluna_navio_diag1 + i] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio diagonal ↘!\n");
            return 1;
        }
    } else {
        printf("Erro: navio diagonal ↘ nao cabe no tabuleiro!\n");
        return 1;
    }

    // Posicionar navio diagonal ↙ (linha aumenta, coluna diminui)
    sobreposicao = 0;
    if (linha_navio_diag2 + TAM_NAVIO <= TAM && coluna_navio_diag2 - (TAM_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (CELULA_OCUPADA(linha_navio_diag2 + i, coluna_navio_diag2 - i)) {
                sobreposicao = 1;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linha_navio_diag2 + i][coluna_navio_diag2 - i] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio diagonal ↙!\n");
            return 1;
        }
    } else {
        printf("Erro: navio diagonal ↙ nao cabe no tabuleiro!\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    printf("    ");
    for (int j = 0; j < TAM; j++) printf("%2d ", j);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < TAM; j++) printf("%2d ", tabuleiro[i][j]);
        printf("\n");
    }
    printf("\nLegenda: 0 = Agua | 3 = Navio\n");

    return 0;
}