#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contaVogais (char *s){
    int cont=0;
    for(int i = 0; s[i]!='\0'; i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            cont++;
        }
    }
    return cont;
}

int retiraVogaisRep1(char *s) {
    int num_vogais_removidas = 0;
    char saux[strlen(s)];
    int i, j=0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            if(s[i]==s[i+1]){
                num_vogais_removidas++;
            }
            else{
                saux[j]=s[i];
                j++;
            }
        }
        else{
            saux[j]=s[i];
            j++;
        }
    }

    saux[j]= '\0';

    for(i = 0; saux[i]!='\0'; i++){
        s[i]=saux[i];
    }

    s[i] = '\0';

    return num_vogais_removidas;
}



int retiraVogaisRep2(char *s) {
    int num_vogais_removidas = 0;
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            if(s[i]==s[i+1]){
                for(j=i; s[j]!='\0';j++){
                    s[j] = s[j+1];
                }
                s[j-1] = '\0';
                i--;
                num_vogais_removidas++;
            }
        }
    }

    return num_vogais_removidas;
}

int duplicaVogais1 (char *s){
    int acrescentados= 0;
    int i,j=0;
    char saux[strlen(s)];
    for(i=0; s[i]!='\0';i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            saux[j]=s[i];
            saux[j+1] = s[i];
            acrescentados++;
            j += 2;
        }
        else{
            saux[j] = s[i];
            j++;
        }
    }

    saux[j]='\0';

    for(i=0; saux[i]!='\0';i++){
        s[i]=saux[i];
    }

    s[i]='\0';
    return acrescentados; 
}

/*
int duplicaVogais2 (char *s){
    int i, j;
    int acrescentados = 0;
    for(i=0; s[i]!='\0';i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            for()
        }
    }
}
*/

// retorna 1 caso esteja ordenado
int ordenado (int v[], int N){
    int i;
    for(i=0; i<N;i++){
        if(v[i]>v[i+1]){
            return 0;
        }
    }
    return 1;
}

void merge(int a[], int na, int b[], int nb, int r[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            r[k] = a[i];
            i++;
        } else {
            r[k] = b[j];
            j++;
        }
        k++;
    }
    
    while (i < na) {
        r[k] = a[i];
        i++;
        k++;
    }

    while (j < nb) {
        r[k] = b[j];
        j++;
        k++;
    }
}

int partition (int v[], int N, int x){
    int i,j=0;
    int saux[N];
    int res=0;

    for(i=0; i<N; i++){
        if(v[i]<=x){
            saux[j] = v[i];
            j++;
            res++;
        }
    }

    for(i=0; i<N; i++){
        if(v[i]>x){
            saux[j] = v[i];
            j++;
        }
    }

    for(i=0; i<j; i++){
        v[i] = saux[i];
    }

}


int main() {   
    int n1[4] = {1,2,3,4};
    int n2[4] = {2,4,5,6};
    int n3[7] = {1,4,2,7,8,3,5};
    int *r = malloc((4 + 4) * sizeof(int)); // allocate space for all the elements
    
    merge(n1, 4, n2, 4, r);
    
    printf("merge n1 com n2: ");
    for (int i = 0; i < 8; i++) { // iterate over 8 elements
        printf("%d ", r[i]);
    }

    partition(n3,7,5);
    printf("partition de n3: ");
    for (int i = 0; i < 7; i++) { // iterate over 8 elements
        printf("%d ", n3[i]);
    }
    
    printf("\nFim dos testes\n");
    free(r); // free the dynamically allocated memory
    return 0;
}