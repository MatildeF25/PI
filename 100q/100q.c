#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


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

ABin newAbin (int r, ABin e, ABin d){
   ABin new = (ABin) malloc (sizeof (struct nodo));

    if(new != NULL){
        new->valor = r;
        new->dir = d;
        new->esq = e;
    }
    return new;
}

int altura (ABin a){
    int alt = 0;
    if(a == NULL){
        return 0;
    }
    int lh = altura(a->esq);
    int rh = altura(a->dir);

    if(lh > rh){
        return alt = lh +1;
    }
    else{
        return alt = rh + 1;
    }    
}

ABin cloneAB (ABin a){    
    if(a==NULL){
        return NULL;
    }
    return newAbin(a->valor, cloneAB(a->esq), cloneAB(a->dir));
}

void mirror (ABin *a){
    if((*a)==NULL){
        return;
    }

    ABin aux = (*a)->dir;
    (*a)->dir = (*a)->esq;
    (*a)->esq = aux;
    mirror(&(*a)->dir);
    mirror(&(*a)->esq);
}

void inorder(ABin a, LInt *l) {
    if (a == NULL) {
        return;
    }
    
    inorder(a->esq, l);

    LInt new_node = newLInt(a->valor, NULL);
    
    if(*l == NULL){
        *l = new_node;
    }
    else{
        LInt atual = *l;
        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = new_node;
        
    }  
    
    inorder(a->dir, l);
}

void preorder (ABin a, LInt *l){
    if(a == NULL){
        return;
    }
    
    LInt new_node = newLInt(a->valor, NULL);
    if(*l == NULL){
        *l = new_node;
    }
    else{
        LInt atual = *l;
        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = new_node;
    }

    preorder(a->esq, l);
    preorder(a->dir, l);
}

void posorder (ABin a, LInt *l){
    if(a == NULL){
        return;
    }
    
    posorder(a->esq, l);
    posorder(a->dir, l);
    
    LInt new_node = newLInt(a->valor, NULL);
    if(*l == NULL){
        *l = new_node;
    }
    else{
        LInt atual = *l;
        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = new_node;
    }

}


int depth (ABin a, int x){
    if(a == NULL){
        return -1;
    }
    if(a->valor == x){
        return 1;
    }
    int ld = depth(a->esq,x);
    int rd = depth(a->dir,x);
    if(ld == -1 && rd == -1) return -1;
    if(ld == -1) return rd + 1;
    if(rd == -1) return rd + 1;

    if(ld<rd){
        return ld + 1;
    }
    else{
        return rd + 1;
    }
}

int freeAB (ABin a){
    if(a == NULL){
        return 0;
    }

    int c = freeAB(a->esq);
    int c2 = freeAB(a->dir);
    free(a);
    return(c+c2+1);
}

int pruneAB(ABin *a, int l) {
    if (*a == NULL) {
        return 0;
    }

    int c = pruneAB(&(*a)->esq, l-1);
    int c2 = pruneAB(&(*a)->dir, l-1);

    if (l<=0) {
        free(*a);
        *a = NULL;
        return c + c2 + 1;
    }

    return c + c2;
}

int iguaisAB (ABin a, ABin b){
    if(a==NULL && b==NULL){
        return 1;
    }    
    if(a==NULL){
        return 0;
    }
    if(b==NULL){
        return 0;
    }

    if(a->valor != b->valor){
        return 0;
    }

    int l = iguaisAB(a->esq,b->esq);
    int r = iguaisAB(a->dir,b->dir);
    if(l==1 && r==1){
        return 1;
    }
    return 0;    
}

LInt nivelL(ABin a, int n) {
    if (a == NULL || n < 1) {
        return NULL;
    }

    if (n == 1) {
        return newLInt(a->valor, NULL);
    }

    LInt left = nivelL(a->esq, n - 1);
    LInt right = nivelL(a->dir, n - 1);

    if(l2 == NULL){
        return l1;
    }
    LInt l = l1;
    while (l->prox!=NULL){
        l = l->prox;
    }
    l->prox = l2;
    return l1;
}

int nivelV (ABin a, int n, int v[]){
    if(a==NULL){
        return 0;
    }

    if(n==1){
        v[0] = a->valor;
        return 1;
    }

    int l = nivelL(a->esq, n-1, v);
    int r = nivelL(a->dir, n-1, v+l);

    return l+r;
}

int dumpAbin(ABin a, int v[], int N) {
    if (a == NULL || N <= 0) {
        return 0;
    }

    int l = dumpAbin(a->esq, v, N);

    if (l >= N) {
        return l;
    }

    v[l] = a->valor;

    int r = dumpAbin(a->dir, v, N - l - 1);

    return l + r + 1;
}

ABin somasAcA (ABin a){
    if(a==NULL){
        return NULL;
    }

    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);

    if(new->esq != NULL){
        new->valor += new->esq->valor;
    }
    if(new->esq != NULL){
        new->valor += new->dir->valor;
    }
    return new;
}

int contaFolhas (ABin a){
    if(a==NULL){
        return 0;
    }

    int l = contaFolhas(a->esq);
    int r = contaFolhas(a->dir);

    if(l==0 && r==0){
        return 1
    }

    return l+r;
}

ABin cloneMirror (ABin a){
    if(a==NULL){
        return NULL;
    }

    ABin new = malloc(sizeof(structnodo));
    new->valor = a->valor;
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);

    return new;
}

int addOrd (ABin *a, int x){
    while (*a != NULL){
        if ((*a)->valor == x){
            return 1;
        }
        if ((*a)->valor > x){
            a = &((*a)->esq);
        }
        else{
            a = &((*a)->dir);
        }
    }

    *a = malloc(sizeof(struct nodo));
    (*a)->valor = x;
    (*a)->esq = NULL;
    (*a)->dir = NULL;

    return 0;    
}

int lookupAB (ABin a, int x){
    while (a != NULL){
        if(a->valor == x){
            return 1;
        }
        if(a->valor > x){
           a = a->esq;  
        } 
        else{
            a = a->dir;
        }
    }
    
    return 0;
}

int depthOrd (ABin a, int x){
    int r = 1;
    while (a != NULL){
        if(a->valor == x){
            return r;
        }
        if(a->valor > x){
            a = a->esq;
            r++;
        }
        else{
            a = a->dir;
            r++;
        }
    }

    return -1;
}

int maiorAB (ABin a){
    int maior = 0;
    while (a!=NULL){
        maior = a->valor;
        a = a->dir;
    }

    return maior;
}

void removeMaiorA (ABin *a){
    while ((*a)->dir != NULL){
        a = &(*a)->dir;        
    }

    ABin temp = *a;
    *a = (*a)->esq;
    free(temp);
}

int quantosMaiores (ABin a, int x){
    if(a == NULL){
        return
    }
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


int main (){
    ABin a = createBinaryTree();
    LInt l = NULL;

    posorder(a, &l);

    while (l!=NULL){
        printf("%d",l->valor);
        l = l->prox;
    }
    printf("\n");

    int r = depth(a,1);

    printf("%d\n",r);

    return 0;
}

