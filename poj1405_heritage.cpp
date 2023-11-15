//very special idea, I first thought solving this problem with 1 / decimal which 
//can be troublesome.
//2   remain 1/2
//3   remain 1/6
//7   remain 1/42
//you can see the rule, remainder is a, the next number is a+1, the next remainder 
//is 1/a*(a+1)
//use large base : for example 1000

#include <stdio.h>
#include <cstring>

const int N = 30001;
int base = 1000, rest1[N], res[20][N] = {0}; 

void mul(int base, int a) {
	int tmp;
    	res[a][0] = 2 * res[a-1][0] - N;
	for (int j=N-1; j>=res[a-1][0]; j--) {
		for (int i=N-1; i>=res[a-1][0]; i--) {
			res[a][i-N+1+j] += res[a-1][i] * res[a-1][j];
		}
		res[a][j] += res[a-1][j];
	}
	tmp = N - 1;
	for (int tmp=N-1; tmp>=res[a][0]; --tmp) {
		if (res[a][tmp]>base-1) {
			res[a][tmp-1] += res[a][tmp] / base;
			res[a][tmp] %= base;
		}
	}
	while (!res[a][res[a][0]]) res[a][0]++;
}

int main() {
    int num, tmp; 
    scanf("%d", &num);
    printf("%d\n", 2);
	printf("%d\n", 3);
	printf("%d\n", 7);
	printf("%d\n", 43);
	res[5][0] = N - 2;
	res[5][N-2] = 1;
	res[5][N-1] = 806;
    for (int i=6; i<=num+1; ++i) {
        mul(base, i);
		res[i-1][N-1] ++;
		printf("%d", res[i-1][res[i-1][0]]);
        for (int j=res[i-1][0]+1; j<N; ++j) {
			printf("%03d", res[i-1][j]);
		}
        printf("\n");
    }
}
