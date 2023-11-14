#include <stdio.h>
#include <cstring>
#include <cmath>

const int N = 1e6 + 10;
char rest[N], res[N], num[N];
int tmp1 = 1, len;

void solve(char res[]) {
    int tmp;
    if (len==1) {
        rest[1] = '\0';
        printf("%d. %s\n", tmp1, rest);
        return;
    }
    res[len-1] = rest[len-1];
    for (int i=len-2; i>0; --i) {
        if (rest[i]-res[i+1]>=0) res[i] = rest[i] - res[i+1] + '0';
        else {
            tmp = i - 1;
            while (rest[tmp]=='0') {
                rest[tmp] = '9';
                tmp--;
            }
            rest[tmp] -= 1;
            res[i] = char(rest[i] - res[i+1] + 10 + '0');
        }
    }
    if (rest[0]>res[1]) {
        res[0] = rest[0]-res[1]+'0';
        res[len] = '\0';
        printf("%d. %s\n", tmp1, res);
    }
    else {
        if ((10+'0'+rest[0]-res[1])<='9') {
            res[0] = 10+rest[0]-res[1]+'0';
            res[len] = '\0';
            printf("%d. %s\n", tmp1, res);
        }
        else printf("%d. IMPOSSIBLE\n", tmp1);
    }
}

int main() {
    int cnt = 1;
    while (scanf("%s", rest)!=EOF) {
        if (strlen(rest)==1&&rest[0]=='0') break;
        len = strlen(rest);
        for (int i=0; i<len; ++i) num[i] = rest[i];
        solve(res);
        tmp1++;
    }
}