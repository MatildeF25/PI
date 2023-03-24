#include <stdio.h>


void swapM (int *x, int *y){
    int aux = *y;
    *y = *x;
    *x = aux;
}

void swap (int v[], int i, int j){
    int aux = v[i];
    v[i]=v[j];
    v[j]=aux;
}

int soma (int v[], int N){
    int res;
    for(int i = 0; i<N;i++){
        res += v[i];
    }
    return res;
}

void inverteArray1 (int v[], int N){
    for(int i = 0; i<N/2; i++){
        swap(v, i, N-i-1);
    }
}

void inverteArray2 (int v[], int N){
    for(int i = 0; i<N/2; i++){
        swapM(&v[i],&v[N-1-i]);
    }
}

int maximum (int v[], int N, int *m){
    if(N>0){
        for (int i = 0; i < N; i++){
            if(v[i]>*m){
            *m = v[i];
            }
    
        }
        return 0;
    }
    else{
        return 1;
    }
}


void quadrados (int q[], int N){
    int quadrado = 0;
    for(int i=-1; i<N-1; i++){
        q[i+1] = i*i + (2*i+1);
    }
}

/*
int main() {
    int arr[] = {1, 4, 2, 7, 5};
    int N = 5;
    int max;
    if (maximum(arr, N, &max) == 0) {
        printf("The maximum element is %d\n", max);
    }
    else {
        printf("Error: the array is empty\n");
    }
    return 0;
}
*/

int main(){
    int q[10];
    int k[10];
    quadrados(q, 10);
    printf("array q: ");
    for (int i = 0; i < 10; i++){
        printf("%d ", q[i]);
    }
    printf("\n");
    return 0;
}