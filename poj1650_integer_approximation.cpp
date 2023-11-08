//It is like a race, a1, a2 take turns to add 1.

#include <stdio.h>
#include <math.h>

void race(double a, int L) {
    int a1 = 1, a2 = 1, res1, res2;
    double e, eabs = 10, tmp;
    while (a1!=L&&a2!=L) {
        e = a - double(a1) / double(a2);
        tmp = fabs(e);
        if (tmp<eabs) {
            eabs = tmp;
            res1 = a1;
            res2 = a2;
        }
        if (e>0) a1++;
        else a2++;
    }
    printf("%d %d", res1, res2);
}
int main() {
    double a;
    int L;
    scanf("%lf%d", &a, &L);
    race(a, L);
}
