#include <stdio.h>

const int N = 100000;
int a[N];

void cal(int max, int num) {
    int tmp, res;
    res =  a[max];
    for (int i=max+1; i<=num; ++i) {
        res *= i;
        while (!(res%10)) res /= 10;
        res %= N;
        a[i] = res;
    }
}

int last(int a) {
    int res;
    while (!(a%10)) {
        a /= 10;
    }
    res = a % 10;
    return res;
}


int main() {
    int num, max = 1;
    a[1] = 1;
    while (scanf("%d", &num)!=EOF) {
        if (num>max) {
            cal(max, num);
            printf("%5d -> %d\n", num, last(a[num]));
            max = num;
        }
        else printf("%5d -> %d\n", num, last(a[num]));
    }
}