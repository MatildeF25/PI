#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;


int nota (Aluno a){
    int i, notaf = 0, nota_miniT = 0;
    for(i=0; i<6; i++){
        nota_miniT += a.miniT[i]*10;
    }
    notaf = 0.75 * a.teste + 0.25 *(nota_miniT/6);

    if(notaf < 10)
        notaf = 0; 
    
    return notaf;
}

int procuraNum1 (int num, Aluno t[], int N){
    int i = 0;
    for(i; i<N; i++){
        if(num == t[i].numero){
            return i;
        }
        else if(t[i].numero>num){
            return -1;
        }
    }
    return -1;
}

int procuraNum (int num, Aluno t[], int N){
    int i = 0;
    for(i; i<N; i++){
        if(num == t[i].numero){
            return i;
        }
    }
    return -1;
}



void swapA (Aluno t[], int a, int b){
    Aluno aux;
    aux = t[a];
    t[a] = t[b];
    t[b] = aux;
}

void ordenaPorNum (Aluno t [], int N){
    int i, j;

    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-i-1; j++) {
            if (t[j].numero > t[j+1].numero) {
                swapA(t,j,j+1);
            }
        }
    }
}

void swapN (int t[], int a, int b){
    int aux;
    aux = t[a];
    t[a]=t[b];
    t[b] = aux;  
}

void criaIndPorNum (Aluno t [], int N, int ind[]){
    int i, j;
    for (i = 0; i < N; i++) {
        ind[i] = i;
    }
    for (i = 0; i < N - 1; i++) {
         for (j = 0; j < N-i-1; j++) {
            if (t[ind[j]].numero > t[ind[j+1]].numero) {
                swapN(ind,j,j+1);
            }
        }
    }
}


void imprimeTurma (int ind[], Aluno t[], int N){
    
    printf("Turma ordenada por número de aluno:\n");
    for(int i = 0; i < N; i++){
        int index = ind[i];
        printf("%d:%s nota:%d\n", t[index].numero, t[index].nome, nota(t[index]));
    }
}


void criaIndPorNome (Aluno t [], int N, int ind[]){
    int i,j;
    for(i=0; i<N; i++){
        ind[i]=i;
    }

    for(i=0 ; i<N-1; i++){
        for(j=0; j<N-i-1;j++){
            if(strcmp(t[ind[j]].nome,t[ind[j+1]].nome)>0){
                swapN(ind,j,j+1);
            }
        }
    }

}



int main() {
    Aluno alunos[] = {
        {4444, "André", {2, 1, 0, 2, 2, 2}, 10.5},
        {2222, "Joana", {2, 2, 2, 1, 0, 0}, 14.5},
        {7777, "Maria", {2, 2, 2, 2, 2, 1}, 18.5},
        {3333, "Paulo", {0, 0, 2, 2, 2, 1}, 8.7},
        {1111, "Ana", {0, 0, 2, 2, 2, 1}, 9.5},
    };
    int num_alunos = 5;

    printf("Lista original:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("%d: %s\n", alunos[i].numero, alunos[i].nome);
    }

    int indices[num_alunos];
    criaIndPorNum(alunos, num_alunos, indices);

    printf("Lista ordenada por indice:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("%d\n", indices[i]);
    }

    imprimeTurma(indices,alunos,num_alunos);

    int ind[num_alunos];

    criaIndPorNome(alunos,num_alunos,ind);

    printf("Lista ordenada por indice:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("%d\n", ind[i]);
    }

    imprimeTurma(ind,alunos,num_alunos);

    return 0;
}


