#include <stdio.h>
#include <cmath>

int main()
{
	double n,p;
	while(scanf("%lf%lf", &n, &p)==2){
		printf("%.0lf\n",pow(p,1.0/n));
	}
}