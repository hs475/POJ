#include <stdio.h>
#include <cstring>

int f[50][50];
char input[1000];

int main() {
    int n, x, y;
    scanf("%d", &n);
    for (int j = 1; j <= n; ++j) {
        memset(f, 0, sizeof(f));
        scanf("%d%d%s", &x, &y, input);
        printf("Bitmap #%d\n", j);
        for (int i = 0; i + 1< strlen(input); ++i) {
            if (input[i] == 'E') {
                f[x+1][y] = 1;
                x++;
                continue;
            }
            if (input[i] == 'N') {
                f[x+1][y+1] = 1;
                y++;
                continue;
            }
            if (input[i] == 'S') {
                f[x][y] = 1;
                y--;
                continue;
            }
            if (input[i] == 'W') {
                f[x][y+1] = 1;
                x--;
                continue;
            }
        }
        for (int i = 32; i >= 1; --i) {
            for (int j = 1; j <= 32; ++j) {
                if (f[j][i] == 1) printf("X");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
}