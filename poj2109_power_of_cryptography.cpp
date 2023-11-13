#include <iostream>
#include <cmath>

const double eps = 1e-6;

int main() {
	double n, p;
	while(scanf("%lf %lf",&n,&p)!=EOF) printf("%.0lf\n", pow(p + eps, 1.0 / n));
}
