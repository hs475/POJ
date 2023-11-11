//use putchar, faster than scanf and printf

#include <stdio.h>
#include <iostream>

const int N = 1e6 + 1;
char a1[N], a2[N], a[N];

void sum() {
    int tmp, tmpn;
    for (int i=N-1; i>=tmp; --i) {
		a[i] += a1[i] + a2[i] - '0';
        if (a[i]>'9') {
            a[i-1] += 1;
            a[i] -= 10;
        }
    }
    while (a[tmp-1]!='0') tmp--;
}

int main() {
    int num, b, c, tmp;
    scanf("%d", &num);
    tmp = N - num;
	getchar();
    for (int i=0; i<num; ++i) {
        a1[tmp+i] = getchar();
		getchar();
		a2[tmp+i] = getchar();
		getchar();
    }
    sum();
    for (int i=tmp; i<N; ++i) putchar(a[i]);
}
