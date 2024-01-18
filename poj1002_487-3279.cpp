#include <stdio.h>
#include <cstring>
#include <algorithm>

int res[100000];
char in[200];
int phone[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};

void input(char in[], int &tmp) {
    int num = 0;
    for (int i=0; i<strlen(in); ++i) {
        if (in[i]!='-') {
            if (in[i]<='9'&&in[i]>='0') num = num * 10 + in[i] - '0';
            else num = num * 10 + phone[in[i]-'A'];
        }
    }
    res[tmp] = num;
    tmp++;
    return;
}

void solve(int tmp) {
    int t = 1, num = 1;
    std::sort(res, res+tmp);
    //for (int i=0; i<tmp; ++i) printf("%d\n", res[i]);
    for (int i=1; i<tmp; ++i) {
        if (res[i]==res[i-1]) num++;
        else {
            if (num>1) {
                printf("%03d-%04d %d\n", res[i-1] / 10000, res[i-1] % 10000, num);
                num = 1;
                t = 0;
            }
        }
        if (i==tmp-1&&num>1) {
            printf("%03d-%04d %d\n", res[i] / 10000, res[i] % 10000, num);
            t = 0;
        }
    }
    if (t) printf("No duplicates. \n");
}

int main() {
    int n, tmp = 0;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%s", in);
        input(in, tmp);
    }
    solve(n);
}
