#include <stdio.h>

int arr[250], arrt[250];

int equal(int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i-1]) return 0;
    }
    return 1;
}

int main() {
    int n, flag, sum;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        sum = 0;
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        int tmp = 5;
        while (1) {
            sum++;
            for (int i = 0; i < n; ++i) {
                arrt[(i+1)%n] = arr[i] / 2;
                arr[i] /= 2;
            }
            for (int i = 0; i < n; ++i) {
                arr[i] += arrt[i];
                if (arr[i] % 2) arr[i]++;
            }
            if (equal(n)) break;
        }
        printf("%d %d\n", sum, arr[0]);
    }
}