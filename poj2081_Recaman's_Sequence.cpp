#include <stdio.h>
#include <math.h>
#include <map>
using namespace std;

const int N = 500000;
int f[N+1];
map <int, int> num;

int main() {
    int max = 0, n;
    f[0] = 0;
    while (scanf("%d", &n)) {
        if (n==-1) break;
        if (max>=n) printf("%d\n", f[n]);
        else {
            for (int i=max+1; i<=n; ++i) {
                if (f[i-1]-i>0&&num.find(f[i-1]-i)==num.end()) f[i] = f[i-1] - i;
                else f[i] = f[i-1] + i;
                num.insert(pair<int, int>(f[i], 1));
            }
            max = n;
            printf("%d\n", f[n]);
        }
    }
}