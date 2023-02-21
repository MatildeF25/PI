#include <stdio.h>

void um(){
    int n,maior;
    printf("introduz um nº: \n");
    scanf ("%d", &n);
    maior = n;

    while(n!=0){
        printf("introduz um nº: \n");
        scanf ("%d", &n);
        if(n>maior){
            maior = n;
        }
    }
    printf("o maior elemento é: %d", maior);
}

void dois(){
    int total;
    int n;
    int i = 0;
    int media;
    printf("introduz um nº: \n");
    scanf ("%d", &n);
    total = n;

     while(n!=0){
        printf("introduz um nº: \n");
        scanf ("%d", &n);
        total += n;
        i++;
    }
    media = total/i;
    printf("a média é: %d\n", media);
}

void tres(){
    int t,n,maior1,maior2 = 0;
    printf("introduz um nº: \n");
    scanf ("%d", &n);
    maior1 = n;

    while(n!=0){
        printf("introduz um nº: \n");
        scanf ("%d", &n);
        if(n>maior2){
            maior2 = n;
            if(maior2>maior1){
                t = maior1;
                maior1 = maior2;
                maior2 = t;
            }
            
        }
    }
    printf("o segundo maior elemento é: %d", maior2);
}

int bitsUm (unsigned int n){
    int r = 0;
    while(n > 0) {
        if(n % 2 != 0) {
            r++;
        }
        n = n/2;
    }
    return r;
}

int trailingZ (unsigned int n){
    int r = 0;
    int a = 32;
    if(n==0){
        return a;
    }
    else{
        while(n > 0) {
            if(n % 2 == 0) {
                r++;
            }
            n = n/2;
        }
    }
    return r;
}

int qDig (unsigned int n){
    int i = 1;
    while (n/10>0){
        n = n/10;
        i++;
    }
    printf("%d\n",i);
    return i;
}

char *mystrcat (char s1[], char s2[]){
    int i = 0;
    int j;
    for(j=0;s1[j]!='\0';j++);

    while (s2[i]!='\0'){
        s1[j]=s2[i];
        i++;
        j++;
    }
    
    s1[j]='\0';
    return s1;

}

int mystrcmp (char s1[], char s2[]){
    int i = 0;
    while(s1[i]!= '\0' && s2[i]!='\0'){
        if(s1[i]==s2[i]){
            i++;
            continue;
        }
        else{
            break;
        }
    }
    
    if(s1[i]=='\0' && s2[i]=='\0'){
        return 0;
    }
    else{
        if (s1[i] < s2[i]) {
            return -1;
        }
        else if (s1[i] > s2[i]) {
            return 1;
        }
    }
}

/*
char *mystrstr (char s1[], char s2[]){
    int i;
    int j;
    if (s2[0] == '\0') return s1;

    for(i=0; s1[i]!='\0'; i++){
        for(j=0; s2[j]!='\0' && s1[i+j]!='\0' && s1[i+j]==s2[j]; j++)

        if(s2[j]=='\0'){
            return s1+i;
        }
        
    }
    return NULL;
}
*/

void strrev (char s[]){
    int i;
    int len = 0;
    char aux;
    for(i=0; s[i]!='\0';i++){
        len++;
    }

    for(i=0; i<(len/2); i++){
        aux = s[i];
        s[i] = s[len-i-1] ;
        s[len-i-1] = aux;   
    }
}

void strnoV (char s[]){
    int i;
    int j;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            for (j = i; s[j] != '\0'; j++) {
                s[j] = s[j + 1];
            }
            i--;
        }
    }
}

void truncW (char t[], int n){
    int i, aux=n, k;

    for (i=0 ; t[i] != '\0' ; i++) {
        if (t[i] == ' ') aux=n;
        else if (aux == 0) {
            for (k=i ; t[k] != '\0' ; k++) {
                t[k] = t[k+1];
            }
            i--;
        }
        else aux--;
    }
}

int length (char s[]) {
    int r = 0, i;

    for (i=0 ; s[i]!='\0' ; i++) r+=1;

    return r; 
}

char charMaisfreq (char s[]){
    int i,j;
    char freq;
    int max_t =0;
    int max = 0;
    
    if(length(s)==0) return 0;

    for(i=0;s[i]!='\0';i++){
        for(j=0;s[j]!='\0';j++){
            if(s[i]==s[j]){
                max++;
            }
        }
        if(max > max_t){
            max_t = max;
            freq = s[i];
        }
        max = 0;
    }
    return freq;
}

int iguaisConsecutivos (char s[]){
    int i;
    char ultimo = 0;
    int r = 0;
    int max_r = 0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]!=ultimo){
            ultimo = s[i];
            r=1;
            if(max_r<r){
                max_r=r;
            }
        }
        else{
            r++;
            if(max_r<r){
                max_r=r;
            }
        }
    }
    return max_r;
}

int difConsecutivos (char s[]){
    int i;
    int r = 0;
    int max_r = 0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]!=s[i+1]){
            r++;
            if(max_r<r){
                max_r=r;
            }
        }
        else{
            r=1;
            if(max_r<r){
                max_r=r;
            }
        }
    }
    return max_r;
}

int maiorPrefixo (char s1 [], char s2 []){
    int i;
    for(i=0; s1[i]!='\0' && s2[i]!='\0';i++){
        if(s1[i]!=s2[i]){
            break;
        }
    }
    return i;
}

int maiorSufixo (char s1 [], char s2 []){
    int ls1 = length(s1)-1;
    int ls2 = length(s2)-1;
    int r = 0;
    for(ls1,ls2; ls1>=0 && ls2>=0; ls1--,ls2--){
        if(s1[ls1]==s2[ls2]){
            r++;
        }
        else{
            break;
        }
    }
    return r;
}


int sufPref (char s1[], char s2[]){
    int i;
    int j=0;
    int r=0;
    int max_r=0;
    for(i=0; s1[i]!='\0';i++){
        if(s1[i]==s2[j]){
            r++;
            if(max_r<r){
                max_r=r;
            }
            j++;
        }
        else{
            r=0;
            j=0;

        }
    }
    return max_r;
}

int contaPal (char s[]){
    int i;
    int r=0;
    
    if(length(s)==0) return 0;
    
    for(i=0;s[i]!='\0';i++){
        if(((s[i-1]==' ') || (s[i-1]==0)) && ((s[i]!=' ') && (s[i]!='\n'))){
            r++;
        }
    }
    return r;
}

int contaVogais (char s[]){
    int i;
    int r = 0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            r++;
        }
    }
    return r;
}

// retorna 0 se c pertence á string s
int elem (char c, char s[]){
    int i;
    for(i=0;s[i]!='\0';i++){
        if(c==s[i]){
            return 0;
        }
    }
    return 1;
}

// retorna 1 se a estiver contida em b e 0 casocontrário
int contida (char a[], char b[]){
    int i;
    for(i=0;a[i]!='\0';i++){
        if(elem(a[i],b)==1){
            return 0;
        }
    }
    return 1;
}

// retorna 0 se s for palindrome e 1 caso contrario
int palindorome (char s[]){
    int l = length(s)-1;
    int i;
    for(i=0;i<length(s)/2;i++){
        if(s[i]!=s[l]){
            return 0;
        }
        l--;
    }
    return 1;
}

int remRep (char x[]){
    int i;
    int j;
    for(i=0;x[i]!='\0';i++){
        if(x[i]==x[i+1]){
            for (j = i; x[j] != '\0'; j++) {
                x[j] = x[j + 1];
            }
            i--;
        }
    }
    return length(x);
}

int limpaEspacos (char x[]){
    int i,j;
    for(i=0;x[i]!='\0';i++){
        if(x[i]==' ' && x[i+1]==' '){
            for (j = i; x[j] != '\0'; j++) {
                x[j] = x[j + 1];
            }
            i--;
        }
    }
    return length(x);
}

void insere (int v[], int N, int x){
    int i,j;
    for(i=0; i<N;i++){
        if(v[i]>x){
            for (j = N-1; j>=i; j--) {
                v[j+1] = v[j];
            }
            v[i] = x;
            N++;
            return;
        }
    }
}

void merge (int r [], int a[], int b[], int na, int nb){
    int i,j;
    for(i=0; i<na;i++){
        r[i]=a[i];
    }
    for(i=0; i<nb;i++){
        insere(r,na+nb,b[i]);
    }
}

int crescente (int a[], int i, int j){
    for(i; i<j;i++){
        if(a[i]>a[i+1]){
            return 0;
        }
    }
    return 1;
}


int retiraNeg(int v[], int N) {
    int i, j;
    int r = 0;
    for (i = 0; i < N; i++) {
        if (v[i] < 0) {
            for (j = i+1; j < N; j++) {
                v[j-1] = v[j];
            }
            r++;
            i--;
            N--;
        }
    }
    return N;
}

int menosFreq (int v[], int N){
    int i;
    int i_min = 0;
    int r = 1;
    int min = N;

    for(i=0;i<N;i++){
        if(v[i]==v[i+1]){
            r++;
        }
        else{
            if(r < min){
                min = r;
                i_min = i;
            }
            r=1;
        }
    }
    return v[i_min];
}

int maisFreq (int v[], int N){
    int i;
    int i_min;
    int r = 1;
    int max = 0;
    for(i=0;i<N;i++){
        if(v[i]==v[i+1]){
            r++;
        }
        else{
            if(r > max){
                max = r;
                i_min = i;
            }
            r=1;
        }
    }
    return v[i_min];
}

int maxCresc (int v[], int N){
    int i;
    int r = 1;
    int max = 0;
    for(i=0;i<N;i++){
        if(v[i]<=v[i+1]){
            r++;
        }
        else{
            if(r > max){
                max = r;
            }
            r=1;
        }
    }
    return max;
}

int elimRep (int v[], int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(v[i]==v[j]){
                for(k=j+1; k<n;k++){
                    v[k-1]=v[k];
                }
                j--;
                n--;
            }
        }
    }
    return n;
}

int elimRepOrd (int v[], int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        if(v[i]==v[i+1]){
            for(k=i+1; k<n;k++){
                v[k-1]=v[k];
            }
            i--;
            n--;
        }
    }
    return n;
}

// retorna 0 se x pertence a a[]
int pertence (int a[], int na, int x){
    int i;
    for(i=0; i<na; i++){
        if(a[i]==x){
            return 0;
        }
    }
    return 1;
}

int comunsOrd (int a[], int na, int b[], int nb){
    int r = 0, i=0, j=0;
    while(i<na && j<nb){
        if(a[i]==b[j]){
            r++;
            i++;
            j++;
        }
        else{
            if(a[i]<b[j]){
                i++;
            }
            else j++;
        }
    }
    return r;
}

int comuns (int a[], int na, int b[], int nb){
    int i,j,r = 0, f=0;
    for(i=0; i<na;i++){
        for(j=0;j<nb && f!=1;j++){
            if(a[i]==b[j]){
                r++;
                f=1;
            }
        }
        f=0;
    }
    return r;
}

int minInd (int v[], int n){
    int menor = v[0];
    int min_i = 0, i;
    for(i=1; i<n;i++){
        if(menor>v[i]){
            menor = v[i];
            min_i = i;
        }
    }
    return min_i;
}

void somasAc (int v[], int Ac[], int N) {
    int i;
    Ac[0] = v[0];
    for (i = 1; i < N; i++) {
        Ac[i] = Ac[i-1] + v[i];
    }
}

int triSup (int N, int m [N][N]) {
    int i, j;
    for(i = 0; i< N; i++){
        for(j = 0; j < i; j++){
            if(m[i][j] != 0)
                return 0;
        }
    }
    return 1;
}


void transposta (int N, float m [N][N]) {
    int i, j, aux;
    for (i = 0; i<N; i++){
        for(j = 0; j < i; j++){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }

}


void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            a[i][j] += b[i][j];
        }
    }
}


int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0; i<N; i++){
        if(v1[i]==1 || v2[i]==1){
            r[i]=1;
        }
        else {
            r[i]=0;
        }
    }
}

int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0; i<N; i++){
        if(v1[i]==1 && v2[i]==1){
            r[i]=1;
        }
        else {
            r[i]=0;
        }
    }
}

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0; i<N;i++){
        if(v1[i]<=v2[i]){
            r[i]=v1[i];
        }
        else{
            r[i]=v2[i];
        }
    }
}

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++){
        if(v1[i] >= v2[i])
            r[i] = v1[i];
        else
            r[i] = v2[i];
    }
}

int cardinalMSet (int N, int v[N]){
    int i, r=0;
    for (i = 0; i<N; i++){
        r += v[i];
    };
    return r;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i=0; i<N; i++){
        switch (mov[i])
        {
        case Norte:
            inicial.y++;
            break;
        case Sul:
            inicial.y--;
            break;
        case Oeste:
            inicial.x--;
            break;
        case Este:
            inicial.x++;
            break;
        default:
            break;
        }
    }
    return inicial;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    for(i=0; i<N; i++){
        if (inicial.x>final.x){
            mov[i]= Oeste;
            inicial.x--;
        }
        else{
            if(inicial.x<final.x){
                mov[i]= Este;
                inicial.x++;
            }
            else{ 
                if(inicial.y>final.y){
                mov[i]= Sul;
                inicial.y--;
                }
                else{
                    if (inicial.y<final.y){
                        mov[i]= Norte;
                        inicial.y++;
                    }
                    else break;
                    
                }
            }
        }
        
    }

    if(inicial.x!=final.x || inicial.y!=final.y){
        return -1;
    }

    return i;
}

int maisCentral (Posicao pos[], int N){
    int i, menor, dist, min_i = 0;
    menor = abs((pos[i].x*pos[i].x)+(pos[i].y*pos[i].y));

    for(i=1; i<N; i++){
        dist = abs((pos[i].x*pos[i].x)+(pos[i].y*pos[i].y));
        if(dist<menor){
            menor = dist;
            min_i = i;
        }
        dist = 0;
    }

    return min_i;
}

int vizinhos (Posicao p, Posicao pos[], int N){
    int i, r = 0;
    for(i=0; i<N; i++){
        if (p.x==pos[i].x && (p.y-1)==pos[i].y){
           r++;
        }
        else{
            if(p.x==pos[i].x && (p.y+1)==pos[i].y){
                r++;
            }
            else{ 
                if(p.y==pos[i].y && (p.x-1)==pos[i].x){
                    r++;
                }
                else{
                    if (p.y==pos[i].y && (p.x+1)==pos[i].x){
                        r++;
                    }   
                }
            }
        }
        
    }

    return r;
}


int main() {
    char s1[] = "axa";
    char s2[] = "xa";
    int prefixo = maiorSufixo(s1,s2);
    printf("%d\n", prefixo);
    return 0;
}


/*
int main() {
    int s1[] = {1, 2, 3, 4, 5, 6, 8, 9};
    insere(s1, 8, 7);
    int i;
    for (i = 0; i < 9; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
    return 0;
}*/