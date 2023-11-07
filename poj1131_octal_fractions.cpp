#include <stdio.h>
#include <string.h>

const int N = 1e6;
char a[N];
int in[N], res[N], rest[N], out[N] = {0}, resn = N - 1, sn;

void mul(int s2[], int t2[], int snt, int tn) {
	int tmp;
	resn = N - 1;
	memset(res, 0, sizeof(res));
	for (int j=tn-1; j>=0; j--) {
		for (int i=N-1; i>N-1-sn; i--) {
			res[i-N+1+ N-tn+j] += s2[i] * t2[j];
			tmp = i-N+1+ N-tn+j;
			while (res[tmp]>9) {
				res[tmp-1] += res[tmp] / 10;
				res[tmp] = res[tmp] % 10;
				tmp--;
			}
			if (resn>tmp) resn = tmp;	
		}
	}	
	memcpy(rest, res, sizeof(rest));
	sn = N - resn;
}

int main() {
    int len = 0, tmp;
    int t[3] = {1, 2, 5}, s[4] = {1, 0, 0, 0};
    while (scanf("%s", a)!=EOF) {
        len = strlen(a);
        memset(out, 0, sizeof(out));
        memset(in, 0, sizeof(in));
        printf("0.");
        for (int i=2; i<len; ++i) {
            in[i+N-len] = a[i] - '0';
            printf("%d", in[i+N-len]);
        }
        printf(" [8] = ");
        len -= 2;
        printf("0.");
        for (int i=N-1; i>=N-len; --i) {
            sn = 1;
            memset(res, 0, sizeof(res));
            memset(rest, 0, sizeof(rest));
            rest[N-1] = in[i];
            for (int j=0; j<i-N+len+1; ++j) mul(rest, t, sn, 3);
            for (int j=0; j<N-1-i; ++j) mul(rest, s, sn, 4);
            
            for (int j=N-1; j>=N-sn; --j) {
                out[j] += res[j];
                tmp = j;
                while (out[tmp]>9) {
				out[tmp-1] += out[tmp] / 10;
				out[tmp] = out[tmp] % 10;
				tmp--;
			    }
            }
        }
        int zero = N-1;
        while (out[zero]==0) zero--;
        for (int i=N-sn; i<N; ++i) printf("%d", out[i]);
        printf(" [10]\n");
    }
}
