#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char s[255];

int main() {
    int res;
    while (gets(s)) {
        if (s[0]=='#') break;
        res = 0;
        for(int i=0; i<strlen(s); ++i) {
            if (s[i]==' ') continue;
            else {
                res += (i + 1) * (s[i] - 'A' + 1);
            }            
        }
        printf("%d\n", res);
    }
    return 0;
}