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

    while (atual != NULL && atual->valor < n){
        ant = atual;
        atual = atual->prox;
    }

    if(atual != NULL && atual->valor == n){
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
    int len = length(*l)/2;
    LInt y = NULL;
    LInt atual = *l, ant;

    for(int i = 0; i<len; i++){
        ant = atual;
        atual = atual->prox;
    }

    if(ant == NULL){
        return NULL;
    }

    ant->prox = NULL;
    y = *l;
    *l = atual;

    return y;
}

int removeAll (LInt *l, int x){
    LInt atual = *l, ant = NULL, next;
    int res = 0;


    while (atual != NULL){
        next = atual->prox;
        if(ant == NULL && atual->valor == x){
            *l = next;
            free(atual);
            atual = next;
            res++;
        }
        else if(ant != NULL && atual->valor == x){
            ant->prox = next;
            free(atual);
            atual = next;
            res++;
        } 
        else {
            ant = atual;
            atual = atual->prox;
        }
    }
    
    return res;
}

int removeDups (LInt *l){
    LInt atual = *l;
    int res = 0;
    if(atual == NULL && atual->prox == NULL){
        return res;
    }

    while (atual){
        res += removeAll(&(atual->prox),atual->valor);
        atual = atual->prox;
    }
    
    return res;
}

int removeMaiorL (LInt *l){
    int maior = 0;
    LInt atual = *l;

    while (atual){
        if(atual->valor > maior){
            maior = atual->valor;
        }
        atual = atual->prox;
    }

    atual = *l;
    LInt ant = NULL, next;

    while (atual){
        next = atual->prox;
        
        if(ant==NULL && atual->valor == maior){
            *l = next;
            free(atual);
            atual = next;
            return maior;
        }
        else if (ant!=NULL && atual->valor == maior){
            ant->prox = next;
            free(atual);
            atual = next;
            return maior;
        }
        else{
            ant = atual;
            atual = next;
        }
        
    }
    
}

void init (LInt *l){
    
    if(*l==NULL){
        return;
    }

    if((*l)->prox == NULL){
        free(*l);
        *l = NULL;
        return;
    }

    LInt atual = *l;
    LInt ant = NULL;

    while (atual->prox != NULL){
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = NULL;
    free(atual);
}

void appendL (LInt *l, int x){
    LInt new = newLInt(x,NULL);
    
    if(*l == NULL){
        *l = new;
        return;
    }

    while ((*l)->prox != NULL){
        l = &((*l)->prox);
    }

    (*l)->prox = new;
}

void concatL (LInt *a, LInt b){
    if(*a == NULL){
        *a = b;
        return;
    }

    while ((*a)->prox != NULL){
        a = &((*a)->prox);
    }

    (*a)->prox = b; 
}

LInt cloneL (LInt l){
    if (l == NULL) {
        return NULL;
    }
    
    LInt new = newLInt(l->valor, NULL);
    LInt atual_new = new;
    l=l->prox;

    while (l != NULL){
        atual_new->prox = newLInt(l->valor,NULL);
        atual_new = atual_new->prox;
        l = l->prox;
    }

    return new;
}

LInt cloneRev (LInt l){
    if(l == NULL){
        return NULL;
    }

    LInt new = newLInt(l->valor,NULL);
    LInt atual_new = new;
    l = l->prox;

    while (l!=NULL){
        atual_new->prox = newLInt(l->valor,NULL);
        atual_new = atual_new->prox;
        l = l->prox;
    }
        
    LInt ant=NULL, next;

    while (new!=NULL){
        next = new->prox;
        new->prox = ant;
        ant = new;
        new = next;
    }
    
    return new;
}


int maximo (LInt l){
    int maior = 0;

    while (l!=NULL){
        if(l->valor>maior){
            maior = l->valor;
        }

        l = l->prox;
    }
    return maior;
}

int take (int n, LInt *l){
    LInt atual = *l;
    LInt ant = NULL;
    int count = 0;
    
    if (n <= 0 || *l == NULL) {
        return count;
    }
    
    while (atual != NULL && count<n){
        ant = atual;
        atual = atual->prox;
        count++;
    }

    if(atual != NULL){
        ant->prox = NULL;
        while (atual!=NULL){
            LInt temp = atual->prox;
            free(atual);
            atual = temp;
        }
    }

    return count;
}

int drop (int n, LInt *l){
    int count = 0;

    while (*l != NULL && count < n) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
        count++;
    }

    return count;
}

LInt Nforward (LInt l, int N){
    int count = 0;

    while (l!=NULL && count<N){
        l = l->prox;
        count++; 
    }

    return l;
}

int listToArray (LInt l, int v[], int N){
    int i = 0;
    
    while (l!=NULL && i<N){
        v[i]=l->valor;
        l=l->prox;
        i++;
    }
    return i;
}

LInt arrayToList (int v[], int N){
    if(N == 0){
        return NULL;
    }
    
    int i = 1;
    LInt l = newLInt(v[0],NULL);
    LInt atual = l;
    
    while (i<N){
       atual->prox = newLInt(v[i],NULL);
       atual = atual->prox;
       i++;
    }
    return l;
}

LInt somasAcL (LInt l){
    if (l == NULL) {
        return NULL;
    }

    int soma = l->valor;
    LInt new = newLInt(soma,NULL);
    LInt atual_new = new;
    l=l->prox;

    while (l!=NULL){
        soma = soma + l->valor;
        atual_new->prox = newLInt(soma,NULL);
        atual_new = atual_new->prox;
        l = l->prox;
    }
    
    return new;
}

void remreps (LInt l){
    if (l == NULL) {
        return;
    }

    LInt atual = l;

    while (atual->prox!=NULL){
        
        if(atual->valor == atual->prox->valor){
            LInt temp = atual->prox;
            atual->prox = atual->prox->prox;
            free(temp);
        }else{
            atual = atual->prox;
        }   
    }
}

LInt rotateL (LInt l){
    if(l==NULL){
        return NULL;
    }

    if(l->prox==NULL){
        return l;
    }

    LInt l1 = l;
    LInt next = l->prox;
    l->prox = NULL;
    l=next;
    LInt atual = l;

    while (atual->prox != NULL){
        atual = atual->prox;
    }
    
    atual->prox = l1;

    return l;
}





LInt parte (LInt l){
    if(l==NULL){
        return NULL;
    }

    LInt new = newLInt(0,NULL);
    LInt atual_new = new;
    int i = 2;
    LInt ant = l;
    LInt atual = l->prox;

    while (atual!=NULL){
        if(i%2==0){
            atual_new->prox = newLInt(atual->valor,NULL);
            atual_new = atual_new->prox;
            ant->prox = atual->prox;
            atual = atual->prox;
        }
        else{
            ant = ant->prox;
            atual = atual->prox;
        }
        i++;
    }
    
    atual_new = new;
    new = new->prox;
    free(atual_new);
    return new;
}

/*-------------------------------------- Arvores Binárias ----------------------------------------------------*/

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


























int main (){
    // create a linked list 1->2->3->NULL
    LInt l = newLInt(1, newLInt(2, newLInt(3, NULL)));
    
    LInt clone = cloneRev(l);

    // print the original list
    printf("Original list: ");
    imprimeL(l);

    // print the cloned list in reverse order
    printf("Cloned list (in reverse order): ");
    imprimeL(clone);


    freeL(l);
    return 0;
}

