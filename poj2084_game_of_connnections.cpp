#include <stdio.h>
#include <cstring>
#include <iostream>

const int N = 1001;
int a[101][N], res[N];

void mul(int k, int g) {
	int tmp;
	memset(res, 0, sizeof(res));
    res[0] = N - 1;
	for (int j=N-1; j>=a[g][0]; j--) {
		for (int i=N-1; i>=a[k][0]; i--) {
			res[i-N+1+j] += a[k][i] * a[g][j];
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

void plus(int num) {
    int min = std::min(res[0], a[num][0]), tmp, tmpn;
    a[num][0] = min;
    for (int i=N-1; i>=min; --i) {
        a[num][i] += res[i];
        tmp = i;
        while (a[num][tmp]>9) {
            tmpn = a[num][tmp];
            a[num][tmp] = tmpn % 10;
            a[num][tmp-1] += tmpn / 10;
            tmp--;
        }
    }
    while (a[num][a[num][0]-1]) a[num][0]--;
    while (!a[num][a[num][0]]) a[num][0]++;
}

void dp(int max, int num) {
    for (int i=max+1; i<=num; ++i) {
        for (int j=0; j<i; ++j) {
            if (i-j-1>j) mul(j, i-j-1);
            else mul(i-j-1, j);
            plus(i);
        }
    }
}

int main() {
    int num, max = 1;
    a[1][N-1] = 1;
    a[0][N-1] = 1;
    for (int i=0; i<=101; ++i) a[i][0] = N - 1;
    while (scanf("%d", &num)!=EOF) {
        if (num==-1) break;
        else {
            if (num<max) {
                for (int i=a[num][0]; i<N; ++i) printf("%d", a[num][i]);
                printf("\n");
            }
            else {
                dp(max, num);
                for (int i=a[num][0]; i<N; ++i) printf("%d", a[num][i]);
                printf("\n");
                max = num;
            }

        }
    }
}
