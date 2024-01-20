#include <stdio.h>

const int n = 10001;
int selfnum[n];


int generator(int i) {
    int res = i;
    while (i) {
        res += i % 10;
        i /= 10;
    }
    return res;
} 

void solve() {
    for (int i=1; i<=n; ++i) {
        selfnum[generator(i)] = 1;
    }    
}

int main() {
    solve();
    for (int i=1; i<=n; ++i) {
        if (!selfnum[i]) printf("%d\n", i);
    }
    return 0;
}