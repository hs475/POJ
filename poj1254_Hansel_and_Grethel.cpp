#include <stdio.h>
#include <cmath>
using namespace std;

double a[2], b[2], c[2], x, y;
const double pi = acos(-1.0);

void line(int x, int y, int z, int t) {
    if (z == 0 || z == 180) {
        a[t] = 1;
        b[t] = 0;
        c[t] = -x;
        return;
    }
    a[t] = 1 / tan(z * pi / 180);
    b[t] = -1;
    c[t] = y - x * 1.0 / tan(z * pi / 180);
}

void solve() {
    //printf("%lfx+%lfy+%lf=0\n", a[0], b[0], c[0]);
    //printf("%lfx+%lfy+%lf=0\n", a[1], b[1], c[1]);
    x = (c[1] * 1.0 * b[0] - c[0] * b[1]) / (a[0] * b[1] - a[1] * b[0]);
    y = (a[0] * c[1] * 1.0 - a[1] * c[0]) / (a[1] * b[0] - a[0] * b[1]);
    return;
}

int main() {
    //freopen("input.txt","r", stdin) ;
    int n;
    double x1, y1, z1, x2, y2, z2, a, b, eps = 1e-7;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1, &x2, &y2, &z2);
        line(x1, y1, z1, 0);
        line(x2, y2, z2, 1);
        solve();
        printf("%.4lf %.4lf\n", x, y);    
    }   
}