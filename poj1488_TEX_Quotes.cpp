#include <stdio.h>
#include <cstring>

char a[100];

int main() {
    int flag = 0;
    while (gets(a)) {
        for (int i = 0; i < strlen(a); ++i) {
            if (a[i] == '"') {
                if (!flag) {
                    printf("``");
                    flag = 1;
                    continue;
                }
                else {
                    printf("''");
                    flag = 0;
                    continue;
                }
            }
            printf("%c", a[i]);
        }
        printf("\n");
    }
}