#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1501;
int res[N], tmp = 1;

void solve() {
    int a = 1, b = 1, c = 1;
    res[1] = 1;
    while (tmp<1501) {
        res[tmp+1] = min(min(res[a] * 2, res[b] * 3), res[c] * 5);
        tmp++;
        if (res[tmp] == (res[a] * 2)) a++;
        if (res[tmp] == (res[b] * 3)) b++;
        if (res[tmp] == (res[c] * 5)) c++;          
    }
}

int main() {
    int n;
    solve();
    while (scanf("%d", &n)) {
        if (!n) break;
        printf("%d", res[n]);                        
    }
}