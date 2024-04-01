#include <stdio.h>
#include <cstring>
#include <string>

char a[10000], tmp[10000];

using namespace std;

const int N = 100;
char s[N + 1][5000];

void solve(int t) {
    sprintf(a, "((A0|B0)|(A0|B0))");
    for (int i = 1; i < t; ++i) {
        sprintf(tmp, "((A%d|B%d)|(%s|((A%d|A%d)|(B%d|B%d))))", i, i, a, i, i, i, i);
        memcpy(a, tmp, sizeof(a));
    }
    printf("%s\n", a);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);

    sprintf(s[0], "((A0|B0)|(A0|B0))");
    for (int i = 1; i < n; i++)
        sprintf(s[i], "((A%d|B%d)|(%s|((A%d|A%d)|(B%d|B%d))))", i, i, s[i-1], i, i, i, i);

    puts(s[n - 1]);
}