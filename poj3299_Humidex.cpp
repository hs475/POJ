#include <stdio.h>
#include <math.h>

int main() {
    char a, b;
    while (scanf("%c", &a)) {
        double T = 150, D = 150, H = 150;
        if (a=='E') break;
        getchar();
        if (a=='T') scanf("%lf", &T);
        else {
            if (a=='D') scanf("%lf", &D);
            else scanf("%lf", &H);
        }
        getchar();
        scanf("%c", &a);
        getchar();
        if (a=='T') scanf("%lf", &T);
        else {
            if (a=='D') scanf("%lf", &D);
            else scanf("%lf", &H);
        }
        if(H==150) {
            H = T+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(D+273.16)))-10);
        }
        else {
            if (D==150) D = 1/((1/273.16)-((log((((H-T)/0.5555)+10.0)/6.11))/5417.7530))-273.16;
            else T = H-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(D+273.16)))-10);
        }
        printf("T %.1f D %.1f H %.1f\n", T, D, H);
        getchar();
    }
}
