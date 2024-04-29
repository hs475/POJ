#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>

int f[30];
char l[150];
std::vector<int> v[30];

void findxy(int n, char c) {
    int x, y;
    x = int(ceil((-1.0 + sqrt(8.0 * n)) / 2));
    y = n - x * (x - 1) / 2;
    x  = (x - 1) * 2 - y + 1;
    y = y - 1;
    v[int(c - 'a')].push_back(x);
    v[int(c - 'a')].push_back(y);
}

int dis(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + 3 * (y1 - y2) * (y1 - y2);
}

int main() {
    int n, flag;
    while (scanf("%d", &n)) {
        flag = 0;
        if (!n) break;
        getchar();
        memset(f, 0, sizeof(f));
        memset(l, 0, sizeof(l));
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n * (n + 1) / 2; ++i) {
            scanf("%c", &l[i]);
            f[int(l[i] - 'a')]++;
            findxy(i + 1, l[i]);
        }
        for (int i = 0; i < 26; ++i) {
            if (f[i] == 3) {
                if (dis(v[i][0], v[i][1], v[i][2], v[i][3]) == dis(v[i][2], v[i][3], v[i][4], v[i][5]) &&\
                    dis(v[i][2], v[i][3], v[i][4], v[i][5]) == dis(v[i][0], v[i][1], v[i][4], v[i][5])) {
                    printf("%c", i + 'a');
                    flag = 1;
                }
            }
        }
        if (!flag) printf("LOOOOOOOOSER!");
        printf("\n");
    }
}