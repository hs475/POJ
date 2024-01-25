#include <stdio.h>
#include <cstring>

int A[51] = {}, s[51];
int gauss[51][51], res[51], t = 0;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

void swap(int a, int b, int N) {
    if (a==b) return;
    for (int i=0; i<=N; ++i) s[i] = gauss[a][i];
    for (int i=0; i<=N; ++i) gauss[a][i] = gauss[b][i];
    for (int i=0; i<=N; ++i) gauss[b][i] = s[i];
}

void Gelimination(int N, int Q) {
    int a1, b1, tmp, a, b;
    memset(gauss, 0, sizeof(gauss));
    gauss[0][N] = 1;
    for (int k=0; k<N; ++k) {
        for (int i=0; i<=k; ++i) gauss[k][k-i] = A[i]; 
        for (int i=k+1; i<N; ++i) gauss[k][N+k-i]= A[i];
    }
    for (int i=0; i<N; ++i) {
        for (int j=i; j<N; ++j) {
            if (gauss[j][i]!=0) {
                swap(j, i, N);
                break;
            }
        }
        for (int j=i+1; j<N; ++j) {
            if (gauss[j][i]!=0) {
                a1 = gauss[i][i];
                b1 = gauss[j][i];
                tmp = gcd(a1, b1);
                if (tmp<0) tmp *= -1;
                a = b1 / tmp;
                b = a1 / tmp;
                for (int k=i; k<=N; ++k) {
                    gauss[j][k] = gauss[j][k] * b - gauss[i][k] * a; 
                }
            }
        }     
    }
    for (int i=0; i<N; ++i) gauss[i][N] = (gauss[i][N] % Q + Q) % Q;  
}

int dfs(int n, int N, int Q) {
    int k;
    if (t==1) return 1;
    if (n==-1) {
        t = 1;
        return 1;
    }
    for (int i=0; i<3; ++i) {
        res[n] = i;
        k = 0;
        for (int j=n; j<N; ++j) k += gauss[n][j] * res[j];
        k %= Q;
        if (k==gauss[n][N]) dfs(n-1, N, Q);
    }  
    if (t) return 1;
    else return 0;      
}



int main() {
    int num, N, Q;
    scanf("%d", &num);
    for (int i=0; i<num; ++i) {
        t = 0;
        scanf("%d%d", &Q, &N);
        memset(A, 0, sizeof(A));
        memset(res, 0, sizeof(res));
        memset(gauss, 0, sizeof(gauss));
        for (int j=0; j<N; ++j) scanf("%d", &A[j]);
        Gelimination(N, Q);
        if (dfs(N-1, N, Q)) printf("A solution can be found\n");
        else printf("No solution\n");
    }
}