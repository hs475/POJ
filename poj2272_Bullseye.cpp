#include <stdio.h>
#include <cmath>

double f[12];

double dis(double x, double y) {
    return x * x + y * y;
}

int point (double x) {
    if (x >= 0 && x <= 9) return 100;
    if (x > 9 && x <= 36) return 80;
    if (x > 36 && x <= 81) return 60;
    if (x > 81 && x <= 144) return 40;
    if (x > 144 && x <= 225) return 20;
    return 0;
}

int main() {
    int r1, r2;
    while (1) {
        r1 = 0;
        r2 = 0;
        for (int i = 0; i < 12; ++i) scanf("%lf", &f[i]);
        if (f[0] == -100) break;
        r1 += point(dis(f[0], f[1]));
        r1 += point(dis(f[2], f[3]));
        r1 += point(dis(f[4], f[5]));
        r2 += point(dis(f[6], f[7]));
        r2 += point(dis(f[8], f[9]));
        r2 += point(dis(f[10], f[11]));
        if (r1 == r2) printf("SCORE: %d to %d, TIE.\n", r1, r2);
        else {
            if (r1 > r2) printf("SCORE: %d to %d, PLAYER 1 WINS.\n", r1, r2);
            else printf("SCORE: %d to %d, PLAYER 2 WINS.\n", r1, r2);
        }       
    }
}