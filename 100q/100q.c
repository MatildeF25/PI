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
    LInt ant = NULL, atual = *l;


    while(atual && atual->valor!=x){
        ant = atual;
        atual = atual->prox;
    }

    if(atual==NULL){
        return 1;
    }

    if(ant){
        ant->prox = atual->prox;
        free(atual);
        return 0;
    }
    else{
        *l = atual->prox;
        return 0;
    }
}


int merge (LInt *r, LInt a, LInt b){
    LInt atual;

    if(a==NULL){
        *r=b;
        return;
    }

    if(b==NULL){
        *r=a;
        return;
    }

    if(a->valor<b->valor){
        *r=a;
        a = a->prox;
    }
    else{
        *r=b;
        b=b->prox;
    }

    atual = *r;

    while (a && b){
        if(a->valor<b->valor){
            atual->prox=a;
            a=a->prox;
        }
        else{
            atual->prox=b;
            b=b->prox;
        }
        atual = atual->prox;
    }

    if(a){
        atual->prox = a;
    }
    else{
        atual->prox = b;
    }
    
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    LInt atualm = NULL, atualM = NULL;

    while(l){
        if(l->valor<x){
            if(*mx == NULL){
                *mx = l;
                atualm = *mx;
            }
            else{
                atualm->prox = l;
                atualm = atualm->prox;
            }
        }
        else{
            if(*Mx == NULL){
                *Mx = l;
                atualM = *Mx;
            }
            else{
                atualM->prox = l;
                atualM = atualM->prox;
            }
        }

        l=l->prox;
    }

    if (atualm != NULL) atualm->prox = NULL;
    if (atualM != NULL) atualM->prox = NULL;
}


