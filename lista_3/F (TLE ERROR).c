#include <stdio.h>
#include <stdlib.h>

int busca(int *v, int n, int x) { // Funcao de busca para saber posicao a ser removida
    for(int i = 0; i < n; i++) {
        if(v[i] == x) return i;
    }
    return -1;
}

int main () {
    int N, M;
    scanf("%d", &N); // Numero de pessoas na fila
    int *fila = malloc(N*sizeof(int)); // Vetor que armazena o identificador de cada pessoa na fila
    if (fila == NULL) {
        return 1; // Verificando falha na alocação
    }

    for(int i = 0; i < N; i++) { // Armazenando valores no vetor
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M); // Numero de pessoas que deixaram a fila

    for(int j = 0; j < M; j++) {
        int saiu_fila = 0; // Finaliza a entrada e manipula os vetores;
        scanf("%d", &saiu_fila);
        int posicao = busca(fila, N, saiu_fila); // Encontra a posicao no vetor da fila a ser removida

        for(int i = posicao; i < N-1; i++) { // Remove o valor que saiu da fila e tras todos os outros 1 casa para a esquerda.
            fila[i] = fila[i+1];
        }
        N--;
    }

    int *nova_fila = realloc(fila, N*sizeof(int)); // Cria um novo vetor para armazenar a nova fila
    if(nova_fila == NULL) {
        free(fila);
        return 1; // Verificando falha na alocação
    }

    for(int k = 0; k < N; k++) { // Loop de impressao
        if(k == N-1) printf("%d", nova_fila[k]); 
        else printf("%d ", nova_fila[k]);
    }

    free(nova_fila); // Liberanddo a memoria do vetor
    

    return 0;
}