#include <stdio.h>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>

struct Node {
    int pro[25];
    char a[25];
    int pnum, s, t;
};

std::string in;
Node f[2000];
std::map <std::string, int> m;

void input() {
    char in[25], tmp[25];
    int pnum = 0, s = 0, p = 0;
    scanf("%d%d%s%s", &pnum, &s, in, tmp);
    if (f[m[tmp]].pro[pnum] == 1) return;
    if (strcmp(in, "Yes") == 0) {
        if (f[m[tmp]].pro[pnum] != 1) {
            f[m[tmp]].pnum += 1;
            f[m[tmp]].s += s;
        }
        if (f[m[tmp]].pro[pnum] >= 2) f[m[tmp]].s += 20 * (f[m[tmp]].pro[pnum] - 1);
        f[m[tmp]].pro[pnum] = 1;
    }
    else {
        if (!f[m[tmp]].pro[pnum]) f[m[tmp]].pro[pnum] = 2;
        else {
            if (f[m[tmp]].pro[pnum] >= 2) f[m[tmp]].pro[pnum]++;
        }
    }
}

bool compare (const Node a, const Node b) {
    std::string at = a.a, bt = b.a;
    if (a.pnum != b.pnum) return a.pnum > b.pnum;
    else {
        if (a.s != b.s) return a.s < b.s;
        else return at < bt;
    }
}

int main() {
    int scenarios, n, pn, t;
    scanf("%d", &scenarios);
    while (scenarios--) {
        scanf("%d", &n);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            memset(f[i].a, '\0', sizeof(f[i].a));
            scanf("%s", f[i].a);
            f[i].pnum = 0;
            f[i].s = 0;
            f[i].t = 0;
            memset(f[i].pro, 0, sizeof(f[i].pro));
            m[f[i].a] = i;
        }
        scanf("%d%d", &pn, &t);
        getchar();
        for (int i = 0; i < t; ++i) input();
        std::sort(f + 1, f + n + 1, compare);
        f[1].t = 1;
        for (int i = 2; i <= n; ++i) {
            if (f[i].pnum == f[i-1].pnum && f[i].s == f[i-1].s) f[i].t = f[i-1].t;
            else f[i].t = i;
        }
        for (int i = 1; i <= n; ++i) {
            printf("%2d. %-8s% 2d% 5d\n", f[i].t, f[i].a, f[i].pnum, f[i].s);
        }
        printf("\n");
        m.erase(m.begin(), m.end());
    }
}
