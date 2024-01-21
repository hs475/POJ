#include <stdio.h>
#include <map>
using namespace std;

map<int, int> num;
int res[1000], rest;

void devide(int a, int b) {
    num.clear();
    printf(".");
    rest = 1;
    while (1) {
        if (num.find(a)!=num.end()) break;
        num.insert(pair<int, int>(a, rest));
        res[rest] = 10 * a / b;
        rest++;
        a = 10 * a % b;     
        if (a==0) {
            for (int i=1; i<rest; ++i) printf("%d", res[i]);
            printf("\nThis expansion terminates.\n");        
            return;    
        }
    }
    for (int i=1; i<rest; ++i) {
        printf("%d", res[i]);
        if (i==49) printf("\n");
        if ((i+1)%50==0&&i!=rest-1) printf("\n");
    }
    printf("\nThe last %d digits repeat forever.\n", rest - num[a]);
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b)) {
        if (!a&&!b) break;
        else devide(a, b);
    }
    return 0;
}
