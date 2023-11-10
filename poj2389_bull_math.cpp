#include <stdio.h>
#include <cstring>

const int N = 101;
char in1[N], in2[N];
int res[N], s[N], t[N];

void mul(int s[], int k[]) {
	int tmp;
	memset(res, 0, sizeof(res));
    res[0] = N - 1;
	for (int j=N-1; j>=k[0]; j--) {
		for (int i=N-1; i>=s[0]; i--) {
			res[i-N+1+j] += s[i] * k[j];
			tmp = i-N+1+j;
			while (res[tmp]>9) {
				res[tmp-1] += res[tmp] / 10;
				res[tmp] = res[tmp] % 10;
				tmp--;
			}
			if (res[0]>tmp) res[0] = tmp;	
		}
	}	
}

int main() {
    int len;
    scanf("%s%s", in1, in2);
    len = strlen(in1);
    for (int i=N-1; i>=N-len; --i) s[i] = in1[i-N+len] - '0';
    s[0] = N - len;
    len = strlen(in2);
    for (int i=N-1; i>=N-len; --i) t[i] = in2[i-N+len] - '0';
    t[0] = N - len;
    mul(s, t);
    for (int i=res[0]; i<N; ++i) printf("%d", res[i]);
}