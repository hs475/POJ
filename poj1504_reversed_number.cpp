#include <stdio.h>
#include <cstring>
#include <iostream>

const int N = 105;
char in1[N], in2[N];
int res1[N], res2[N];

void plus() {
    int tmp, tmpn;
    int min = std::min(res1[0], res2[0]);
    for (int i=N-1; i>=min; --i) {
        res2[i] += res1[i];
        tmp = i;
        while (res2[tmp]>9) {
            tmpn = res2[tmp];
            res2[tmp] = tmpn % 10;
            res2[tmp-1] += tmpn / 10;
            tmp--;
        }
    }
    res2[0] = min - 1;
    while (!res2[res2[0]]) res2[0]++;
}

int main() {
    int num, len1, len2, tmp;
    scanf("%d", &num);
    for (int i=0; i<num; ++i) {
        scanf("%s%s", in1, in2);
        len1 = strlen(in1);
        tmp = 0;
        for (int i=N-1; i>=N-len1; --i) res1[i] = int(in1[tmp++] - '0');
        res1[0] = N - len1;
        len2 = strlen(in2);
        tmp = 0;
        for (int i=N-1; i>=N-len2; --i) res2[i] = int(in2[tmp++] - '0');
        res2[0] = N - len2;
        plus();
        int start = N - 1;
        while (!res2[start]) start--;
        for (int i=start; i>=res2[0]; --i) printf("%d", res2[i]);
        memset(res1, 0, sizeof(res1));
        memset(res2, 0, sizeof(res2));
        printf("\n");
    }
}