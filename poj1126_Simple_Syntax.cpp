#include <stdio.h>
#include <cstring>

char f[300];

int find(char *f)
{
    if (f[0] <= 'z' && f[0] >= 'p')
        return 1;
    if (f[0] == 'N')
    {
        int x = find(f + 1);
        if (x == -1)
            return x;
        return 1 + x;
    }
    if (f[0] == 'I' || f[0] == 'D' || f[0] == 'E' || f[0] == 'C')
    {
        int x = find(f + 1);
        if (x == -1)
            return x;
        int y = find(f + 1 + x);
        if (y == -1)
            return x;
        return 1 + x + y;
    }
    return -1;
}

int solve(int k) {
    int t;
    if (f[k]>='p'&&f[k]<='z') return k;
    while (f[k]=='N') k++;
    t = k;
    if (f[k]=='C'||f[k]=='D'||f[k]=='E'||f[k]=='I') {
        t = solve(k+1);
        t = solve(t+1);
    }
    return t;  
}

int main() {
    while (scanf("%s", f)!=EOF) {
        int flag = 0;
        for (int i=0; i<=strlen(f)-1; ++i) {
            if ((f[i]<'p'||f[i]>'z')&&f[i]!='C'&&f[i]!='D'&&f[i]!='E'&&f[i]!='I') {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("NO\n");
            continue;
        }
        if (find(f) == (signed int)strlen(f))
            printf("YES\n");
        else
            printf("NO\n");

    }
}