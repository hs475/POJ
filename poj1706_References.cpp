#include <stdio.h>
#include <cstring>

int desn = 1, des1[1000] = {0}, des2[1000] = {0};
char des[1000][4][100], f[100];

bool blank(char s[]) {
    for(int i = 0; i < strlen(s); ++i) {
        if(s[i] != ' ') return false;
    }
    return true;
}

void match() {
    int k, l;
    for (int i = 0; i < strlen(f); ++i) {
        if (f[i] == '[') {
            l = i + 1;
            k = f[l] - '0';
            while (f[l + 1] != ']') {
                k = k * 10 + f[l + 1] - '0';
                l++;
            }
            if (!des2[k]) {
                des1[desn] = k;
                des2[k] = desn;
                printf("[%d]", desn);
                desn++;
            }
            else printf("[%d]", des2[k]);
            i = l + 1;
        }
        else putchar(f[i]);
    }
    putchar('\n');
}
 
void input() {
    int n, t, num;
    while (gets(f) != NULL) {
        if (blank(f)) continue;
        if (f[0] == '[') {
            n = 0;
            num = 2;
            t = f[1] - '0';
            while (f[num] != ']') {
                t = t * 10 + f[num] - '0';
                num++;
            }
            while (1) {
                memcpy(des[t][n], f, sizeof(f));
                n++;
                if (gets(f) == NULL || blank(f)) break;
            }
        }
        else {
            while (1) {
                match();
                if (gets(f) == NULL || blank(f)) break;
            }
            putchar('\n');
        }
    }
}

void output() {
    int l, k;
    for (int i = 1; i < desn; ++i) {
        l = 0;
        k = 1;
        printf("[%d]", i);
        while (des[des1[i]][0][l] != ']') l++;
        for (int j = l + 1; j < strlen(des[des1[i]][0]); ++j) putchar(des[des1[i]][0][j]);
        putchar('\n');
        while (!blank(des[des1[i]][k])) {
            printf("%s\n", des[des1[i]][k]);
            k++;
        }
        putchar('\n');
    }
}

int main() {
    input();
    output();
}