//very special idea, I first thought sloving this problem with 1 / decimal which 
//can be troublesome.
//2   remain 1/2
//3   remain 1/6
//7   remain 1/42
//you can see the rule, remainder is a, the next number is a+1, the next remainder 
//is 1/a*(a+1)

#include <stdio.h>
#include <cstring>

const int N = 100001;
int rest1[N], rest2[N], res[N]; 

void mul(int s[], int t[]) {
	int tmp;
	memset(res, 0, sizeof(res));
    res[0] = N - 1;
	for (int j=N-1; j>=t[0]; j--) {
		for (int i=N-1; i>=s[0]; i--) {
			res[i-N+1+j] += s[i] * t[j];
			tmp = i-N+1+j;
			while (res[tmp]>9) {
				res[tmp-1] += res[tmp] / 10;
				res[tmp] = res[tmp] % 10;
				tmp--;
			}
			if (res[0]>tmp) res[0] = tmp;	
		}
	}	
}

int main() {
    int num, tmp; 
    rest1[N-1] = 2;
    rest1[0] = N - 1;
    scanf("%d", &num);
    printf("%d\n", 2);
    memcpy(res, rest1, sizeof(res));
    for (int i=1; i<num; ++i) {
        memcpy(rest2, rest1, sizeof(rest1));
        rest2[N-1]++;
        tmp = N - 1;
        while (rest2[tmp]>9) {
            rest2[tmp] = 0;
            rest2[tmp-1] += 1;
            tmp--;
        }
        while (rest2[rest2[0]-1]!=0) rest2[0]--; 
        mul(rest1, rest2);
        for (int i=rest2[0]; i<N; ++i) printf("%d", rest2[i]);
        printf("\n");
        memcpy(rest1, res, sizeof(rest1));
    }
}

