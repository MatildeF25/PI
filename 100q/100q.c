typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

int length (LInt l){
    int i;
    while (l)
    {
        i++;
        l = l->prox;
    }
    return i;
}

void freeL (LInt l){
    LInt aux;
    while(l->prox){
        aux = l;
        l= l->prox;
        free(aux);
    }
}

void imprimeL (LInt l){
    while (l){
        printf("%d, ", l->valor);
        l = l->prox;
    }

}