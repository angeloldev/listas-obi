#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int fitas[N];
    for (int i = 0; i < N; i++) scanf("%d", &fitas[i]);

    for (int i = 0; i < N; i++) {
        if (fitas[i] == -1) {
            int direita = N, esquerda = N;

            // procura 0 à direita
            for (int j = 1; i + j < N; j++) {
                if (fitas[i+j] == 0) {
                    direita = j;
                    break;
                }
            }

            // procura 0 à esquerda
            for (int k = 1; i - k >= 0; k++) {
                if (fitas[i-k] == 0) {
                    esquerda = k;
                    break;
                }
            }

            int menor = (direita < esquerda ? direita : esquerda);
            if (menor >= 9) menor = 9;
            fitas[i] = menor;
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d", fitas[i]);
        if (i < N-1) printf(" ");
    }
    printf("\n");

    return 0;
}
