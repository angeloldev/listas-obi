#include <stdio.h>

int main () {
    int N;
    scanf("%d", &N);

    int sequencia[N];
    for(int i = 0; i < N; i ++) scanf("%d", &sequencia[i]); //guarda a sequencia no vetor

    for (int j = 0; j <= N/2; j++) {
        if(sequencia[j] + sequencia[N-1-j] == sequencia[j+1] + sequencia[N-2-j]) { //precisa tirar 1 do ultimo indice para retirar o '\0'
            if (j == N/2) printf("S"); continue;
        }
        else printf("N"); break;
    }
}