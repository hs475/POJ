#include <stdio.h>
#include <cstring>

const int N = 1001;
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
    int num, tmp, total[10];
    while (scanf("%d", &num)!=EOF) {
        if (!num) break;
        memset(total, 0, sizeof(total));
        memset(rest1, 0, sizeof(rest1));
        memset(rest2, 0, sizeof(rest2));
        rest2[N-1] = 1;
        rest2[0] = N - 1;
        rest1[N-1] = 1;
        rest1[0] = N - 1;
        for (int i=2; i<=num; ++i) {
            rest2[N-1]++;
            tmp = N - 1;
            while (rest2[tmp]>9) {
                rest2[tmp] = 0;
                rest2[tmp-1]++;
                tmp--;
            }
            while (rest2[rest2[0]-1]!=0) rest2[0]--; 
            mul(rest1, rest2);
            memcpy(rest1, res, sizeof(rest1));
        }
        for (int i=res[0]; i<=N-1; ++i) total[res[i]]++;
        printf("%d! --\n", num);
        printf("   (0)   %d", total[0]);
        printf("   (1)   %d", total[1]);
        printf("   (2)   %d", total[2]);
        printf("   (3)   %d", total[3]);
        printf("   (4)   %d", total[4]);
        printf("\n");
        printf("   (5)   %d", total[5]);
        printf("   (6)   %d", total[6]);
        printf("   (7)   %d", total[7]);
        printf("   (8)   %d", total[8]);
        printf("   (9)   %d", total[9]);
        printf("\n");
    }
}