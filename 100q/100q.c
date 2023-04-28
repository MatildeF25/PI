#include <stdio.h>
#include <stdlib.h>


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
    int res = 0;
    if(l == NULL){
        return res;
    }
    while(l!=NULL){
        res++;
        l = l->prox;
    }
    return res;

}

void freeL (LInt l){
    
    while (l!=NULL){
        LInt temp = l;
        l = l->prox;
        free(temp);
    }
}

void imprimeL (LInt l){
    while(l!=NULL){
        printf("%d - ", l->valor);
        l = l->prox;
    }
}


LInt reverseL (LInt l){
    LInt ant = NULL;
    LInt next;

    while(l!=NULL){
        next = l->prox;
        l->prox = ant;
        ant = l;
        l = next;
    }

    return l;
}

void insertOrd (LInt *l, int n){
    LInt new = newLInt(n, NULL);
    LInt ant = NULL;
   
    while(*l != NULL && (*l)->valor <= n){
        ant = *l;
        l = &(*l)->prox;
    }

    if(ant != NULL){     // adicionar no meio ou fim da lista
        new->prox = *l;
        ant->prox = new;
    } 
    else{               // adicionar no inicio da lista ou numa lista vazia
        new->prox = *l;
        *l = new;
    }
}


int removeOneOrd (LInt *l, int n){
    LInt atual = *l, ant = NULL;

    while (atual != NULL && atual->valor < x){
        ant = atual;
        atual = atual->prox;
    }

    if(atual != NULL && atual->valor == x){
        if(ant == NULL){ // remove o primeiro elemento
            *l = atual->prox;
        }
        else{ // remove elementodo meio ou do fim
            ant->prox = atual->prox;
        }
        free(atual);
        return 1;
    }

    return 0;
}

void merge (LInt *r, LInt a, LInt b){
    LInt atual = newLInt(0,NULL);
    *r = atual;

    while(a!=NULL && b!=NULL){
        if(a->valor > b->valor){
            atual->prox = b->valor;
            b = b->prox;
        }
        else{
            atual->prox = a->valor;
            a = a->prox;
        }
        atual = atual->prox;
    }

    if(a==NULL){
        atual->prox = b;
    }
    else{
        atual->prox = a;
    }

    atual = *r;
    *r = (*r)->prox;
    free(atual);
}


void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    *mx = newLInt(0,NULL);
    *Mx = newLInt(0,NULL);

    LInt atual_mx = *mx;
    LInt atual_Mx = *Mx;

    while(l){
        if(l->valor < x){
            atual_mx->prox = l;
            l = l->prox;
            atual_mx = atual_mx->prox;
            atual_mx->prox = NULL; 
        }
        else{
            atual_Mx->prox = l;
            l = l->prox;
            atual_Mx = atual_Mx->prox;
            atual_Mx->prox = NULL;
        }
    }

    atual_mx = *mx;
    *mx = (*mx)->prox;
    free(atual_mx);

    atual_Mx = *Mx;
    *Mx = (*Mx)->prox;
    free(atual_Mx);
}

LInt parteAmeio (LInt *l){
    int len = length(*l);
    LInt y = NULL;

    while (){

        
    }
    


}







int main (){
    // create a linked list 1->2->3->NULL
    LInt l = newLInt(1, newLInt(2, newLInt(3, NULL)));

    // print the length of the linked list
    printf("Length of the linked list: %d\n", length(l));
    imprimeL(l);

    freeL(l);
    return 0;
}

