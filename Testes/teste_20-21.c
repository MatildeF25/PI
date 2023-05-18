#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

int sumhtpo (int n) {
    int r = 0;
    int i = 0;
    while (n != 1 && i!=100) {
        r += n;
        if (n%2 == 0) n = n/2; 
        else n = 1+(3*n);
        i++;
    }

    if(i<100){
        return -1;
    }
    return r;
}


int quantidade (int v[], int N, int x){
    int i = 0;
    int r = 0;
    for(i; i<N; i++){
        if(v[i]==x){
            r++;
        }
    }
    return r;
}

int moda(int v[], int N, int *m){
    int quant = 0;
    int num;
    int max = 0;

    for(int i = 0; i<N; i++){
        quant = quantidade(v,N,v[i]);
        if(quant > max){
            max = quant;
            num = v[i];
        }
    }
    *m = num;

    for(int i = 0; i<N; i++){
        quant = quantidade(v,N,v[i]);
        if(quant == max && num!=v[i]){
            return 0;
        }
    }

    return max;
}

int procura (LInt *l, int x){
    LInt atual = *l;
    LInt ant = NULL;
    
    while (atual != NULL && atual->valor != x){
        ant = atual;
        atual = atual->prox;
    }

    if(atual != NULL && atual->valor == x){
        if(ant == NULL){
            return 1;
        }
        else{
            ant->prox = atual->prox;
            atual->prox = *l;
            *l = atual;
            return 1;
        }
    }
    return 0;
}

typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;


int freeAB(ABin a){
    if(a == NULL){
        return 0;
    }

    int e = freeAB(a->esq);
    int r = freeAB(a->dir);

    free(a);

    return 1 + (e + r);
}


ABin createBinaryTree() {
    ABin root = (ABin) malloc(sizeof(struct nodo));
    root->valor = 1;

    root->esq = (ABin) malloc(sizeof(struct nodo));
    root->esq->valor = 2;
    root->esq->esq = (ABin) malloc(sizeof(struct nodo));
    root->esq->esq->valor = 4;
    root->esq->esq->esq = NULL;
    root->esq->esq->dir = NULL;
    root->esq->dir = (ABin) malloc(sizeof(struct nodo));
    root->esq->dir->valor = 5;
    root->esq->dir->esq = NULL;
    root->esq->dir->dir = NULL;

    root->dir = (ABin) malloc(sizeof(struct nodo));
    root->dir->valor = 3;
    root->dir->esq = (ABin) malloc(sizeof(struct nodo));
    root->dir->esq->valor = 6;
    root->dir->esq->esq = NULL;
    root->dir->esq->dir = NULL;
    root->dir->dir = (ABin) malloc(sizeof(struct nodo));
    root->dir->dir->valor = 7;
    root->dir->dir->esq = NULL;
    root->dir->dir->dir = NULL;

    return root;
}


// main que testa a freeAB
int main() {
    ABin a = createBinaryTree();
    int r = freeAB(a);
    printf("r = %d\n", r);
    return 0;
}
