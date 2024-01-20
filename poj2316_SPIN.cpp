#include <stdio.h>
#include <cstring>

char in[10], in1[10];

int main() {
    scanf("%s", in);
    while (scanf("%s", in1)!=EOF) {
        printf("%cdddddd\n", in[0]);
        if (in1[0]==' ') break;
        for (int i=0; i<strlen(in); ++i) {
            in[i] = ((in1[i] - '0') + (in[i] - '0')) % 10 + '0';
        }
    }    
    for (int i=0; i<=strlen(in); ++i) printf("%c  ", in[i]);
    printf("\n");
}