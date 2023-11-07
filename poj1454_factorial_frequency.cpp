//notice the output format and number "1"

#include <stdio.h>
#include <cstring>

const int N = 1001;
int rest1[N], rest2[N], res[N], total[10];

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
    while (scanf("%d", &num)!=EOF) {
        if (!num) break;
        memset(total, 0, sizeof(total));
        memset(rest1, 0, sizeof(rest1));
        memset(rest2, 0, sizeof(rest2));
        rest2[N-1] = 1;
        rest2[0] = N - 1;
        rest1[N-1] = 1;
        rest1[0] = N - 1;
        memset(res, 0, sizeof(res));
        res[0] = N - 1;
        res[N-1] = 1;
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
        printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n", total[0], total[1], total[2], total[3], total[4]);
        printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n", total[5], total[6], total[7], total[8], total[9]);
    }
}