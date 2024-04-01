#include <stdio.h>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
using namespace std;

char f[5][1000][200];
int a[5][1000] = {0};

int input(int k) {
    int t = 0, tmp;
    while (1) {
        tmp = 1;
        scanf("%s", f[k][t]);
        if (f[k][t][0] == '<') {
            while (f[k][t][tmp] != '>') tmp++;
            for (int j = tmp; j < 200; ++j) f[k][t][j] = '\0';
            a[k][t] = 1;
        }
        t++;
        if (getchar() == '\n') break;
    }
    return t;
}

void solve(int t) {
    int flag = 1;
    map <string, string> m1, m2;
    for (int i = 0 ; i < t; ++i) {
        if (a[0][i] && a[1][i]) continue;
        if (!a[0][i] && !a[1][i]) continue;
        else {
            if (a[0][i]) {
                if (m1.find(f[0][i]) != m1.end() && m1[f[0][i]] != f[1][i]) {
                    flag = 0;
                    break;
                }
                if (m1.find(f[0][i]) == m1.end()) {
                    m1[f[0][i]].resize(200);
                    m1[f[0][i]] = f[1][i];
                }
            }
            else {
                if (m2.find(f[1][i]) != m2.end() && m2[f[1][i]] != f[0][i]) {
                    flag = 0;
                    break;
                }
                if (m2.find(f[1][i]) == m2.end()) {
                    m2[f[1][i]].resize(200);
                    m2[f[1][i]] = f[0][i];
                }
            }
        }
    }
    if (flag) {
        for (int i = 0; i < t; ++i) {
            if (a[0][i] && a[1][i]) {
                if (m1.find(f[0][i]) != m1.end()) {
                    printf("%s ", m1[f[0][i]].c_str());
                    m2[f[1][i]] = m1[f[0][i]];
                }
                else {
                    if (m2.find(f[1][i]) != m2.end()) {
                        printf("%s ", m2[f[1][i]].c_str());
                        m1[f[0][i]] = m2[f[1][i]];
                    }
                    else printf("x ");
                }
                continue;
            }
            if (!a[0][i] && !a[1][i]) printf("%s ", f[0][i]);
            else {
                if (a[0][i]) printf("%s ", m1[f[0][i]].c_str());
                else printf("%s ", m2[f[1][i]].c_str());
            }
        }
    }
    else printf("-");
    printf("\n");
}

int main() {
    int n, t1, t2;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        memset(a, 0, sizeof(a));
        t1 = input(0);
        t2 = input(1);  
        if (t1 != t2) printf("-\n");
        else solve(t1);
    }
}
