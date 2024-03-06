#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int flag[50];
char a[50];
string f[50];

void solve(int n) {
    int num, t, f1, f2 = 1;
    for (int i = 0; i <= n; ++i) {
        f1 = 0;
        memset(flag, 0, sizeof(flag));
        num = f[i].length();
        if (f[i].length() != strlen(a)) continue;
        for (int t = 0; t <= f[i].length() - 1; ++t) {
            for (int k = 0; k <= f[i].length() - 1; ++k) {
                if (a[t] == f[i][k] && !flag[k]) {
                    num--;
                    flag[k] = 1;
                    break;
                }
                if (k == f[i].length() - 1 && a[t] != f[i][k]) {
                    f1 = 1;
                    break;
                }
            }
            if (f1) break;
        }
        //printf("%d\n", num);
        if (!num) {
            cout << f[i] << endl;
            f2 = 0;
        }       
    }
    if (f2) printf("NOT A VALID WORD\n");
    printf("******\n");
}



int main() {
    int n = 0;
    while (cin >> f[n]) {
        if (f[n][0] == 'X') {
            n--;
            break;
        }
        n++;
    }
    sort(f, f + n + 1);
    while (scanf("%s", a)) {
        if (a[0] == 'X') break;
        solve(n);
    }
}