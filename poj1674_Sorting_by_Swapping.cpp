#include <stdio.h>

int arr[10005] = {0};

int main() {
    int t, n, tmp, sum, t1, t2;
    scanf("%d", &t);
    while (t--) {
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
        for (int i = 1; i <= n; ++i) {
            if (arr[i] == i) continue;
            t1 = arr[i];
            while (t1 != arr[t1]) {
                sum++;
                t2 = arr[t1];
                arr[t1] = t1;
                t1 = t2;
            }
            sum--;
        }
        printf("%d\n", sum);
    }  
}
