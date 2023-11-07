#include <stdio.h>
#include <string.h>

int res1[2500], resn = 2499, sn = 6, rn = 1, d, sd=0;
int  s[2500] = {0}, res[2500] = {0}, rest[2500] = {0};

void mul(int s2[], int t2[], int sn, int tn) {
	int tmp;
	resn = 2499;
	memset(res, 0, sizeof(res));
	for (int j=2499; j>2499-tn; j--) {
		for (int i=2499; i>2499-sn; i--) {
			res[i-2499+j] += s2[i] * t2[j];
			tmp = i-2499+j;
			while (res[tmp]>9) {
				res[tmp-1] += res[tmp] / 10;
				res[tmp] = res[tmp] % 10;
				tmp--;
			}
			if (resn>tmp) resn = tmp;	
		}
	}	
	memcpy(rest, res, sizeof(rest));
	rn = 2500 - resn;
}

void square() {
	int tmp = 0;
	resn = 2499;
	memset(res1, 0, sizeof(res1));
	for (int j=2499; j>2499-sn; j--) {
		for (int i=2499; i>2499-sn; i--) {
			res1[i-2499+j] += s[i] * s[j];
			tmp = i-2499+j;
			while (res1[tmp]>9) {
				res1[tmp-1] += res1[tmp] / 10;
				res1[tmp] = res1[tmp] % 10;
				tmp--;
			}
			if (resn>tmp) resn = tmp;	
		}
	}
	memcpy(s, res1, sizeof(s));
	sn = 2500 - resn;
}

void exponentiation() {
	int d1 = d, zero = 2499;
	while (d>1) {
		if (d%2) {
			mul(rest, s, rn, sn);
			d -= 1;
		}
		else {
			d /= 2;
			square();
		}
	}
	mul(rest, s, rn, sn);
	for (int i=2500-rn; i<=2499-sd*d1; ++i) printf("%d", res[i]);
	while (zero>=2500-sd*d1) {
		if (res[zero]==0) zero--;
		else break;
	}
	if (zero>2500-sd*d1) printf(".");
	for (int i=2500-sd*d1; i<=zero; ++i) printf("%d", res[i]);
	printf("\n");
}

int main() {
    char s1[6], t1[6];
	rest[2499] = 1;
	while (scanf("%s%d", s1, &d) == 2) {
		int tmp = 2499;
		for (int i=5; i>=0; --i) {
			if (s1[i]=='.') {
				sd = 5 - i;
				sn = 5;
			}
			else {
				s[tmp] = s1[i] - '0';
				tmp--;
			}
		}
		if (s[2500-sn]==0) sn = 4;
		exponentiation();
		memset(res, 0, sizeof(res));
		memset(rest, 0, sizeof(rest));
		rest[2499] = 1;
		rn = 1;
		sd = 0;
		sn = 6;
	}
    return 0;
}



//for (int i=N-1; i>=N-len; --i) {
            //rest[N-1] = in[i];
            //for (int j=0; j<i-N+len+1; ++i) mul(rest, t, sn, 3);
        //}
