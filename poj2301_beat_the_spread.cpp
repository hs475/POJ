#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        if (a<b&&(a+b)%2==1) printf("impossible\n");
        else printf("%d %d\n", (a+b)/2, (a-b)/2);
    }
}