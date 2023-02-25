typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}


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

LInt reverseL (LInt l){
    if(!l){
        return NULL;
    }
    LInt ant=NULL, next;

    while(l){
        next = l->prox;
        l->prox = ant;
        ant = l;
        l = next;
    }

    return ant;
}

void insertOrd (LInt *l, int x){
    LInt new = newLInt(x,NULL);
    LInt ant = NULL;
   
    while ((*l) && (*l)->valor <= x){
        ant = *l;
        l = &(*l)->prox;
    }

    if(ant){
        new->prox = *l;
        ant->prox = new;
    }
    else{
        new->prox = (*l);
        *l = new;
    }
    
}

int removeOneOrd (LInt *l, int x){
    LInt ant = NULL;

    while((*l) && (*l)->valor != x){
        ant = *l;
        l = &(*l)->prox;
    }

    if(l==NULL){
        return 1;
    }

    if(ant){
        ant->prox = &(*l)->prox;
        free(l);
        return 0;
    }
    else{
        *l = &(*l)->prox;
        return 0;
    }
}