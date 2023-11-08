#include <stdio.h>
#include <iostream>

const int N = 1e6;
int a1[N], a2[N];

void sum() {
    int tmp, tmpn;
    for (int i=N-1; i>=a1[0]; --i) {
        a2[i] += a1[i];
        tmp = i;
        while (a2[tmp]>9) {
            tmpn = a2[tmp];
            a2[tmp]  = tmpn % 10;
            a2[--tmp] += tmpn / 10;
        }
    }
    while (a2[a2[0]-1]) a2[0]--;
}

int main() {
    int num, a, b;
    scanf("%d", &num);
    a1[0] = N - num;
    a2[0] = N - num;
    for (int i=0; i<num; ++i) scanf("%d%d", &a1[N-num+i], &a2[N-num+i]);
    sum();
    for (int i=a2[0]; i<N; ++i) printf("%d", a2[i]);
}