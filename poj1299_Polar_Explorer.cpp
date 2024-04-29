#include <stdio.h>
#include <cstring>
#include <string>

int flag;
char a[20];

int solve(int x, int y, int z) {
    if (z > 180) z = 360 - z;
    double tmp = 2 * 3.14159 * x * z / 360;
    double need = 2 * tmp / 5;
    if (need <= y) {
        y -= need;
        flag = 1;
    }
    else {
        flag = 0;
        y *= 5;
    }
    return y;
}

int main() {
    int x, y, z, res;
    while (scanf("%s", a)) {
        if (strcmp(a, "ENDOFINPUT") == 0) break; 
        scanf("%d%d%d", &x, &y, &z);
        res = solve(x, y, z);
        if (flag) printf("YES %d\n", res);
        else printf("NO %d\n", res);
        scanf("%s", a);
    }
}
