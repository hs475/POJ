#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>

std::string a, b, c, d;

int main() {
    int n, flag;
    a = "too high";
    b = "too low";
    c = "right on";
    while (1) {
        flag = 1;
        scanf("%d", &n);
        if (!n) break;
        int l = 1, r = 10;
        while (1) {
            getline(std::cin, d);
            if (d == a) r = std::min(r, n - 1);
            if (d == b) l = std::max(l, n + 1);
            if (d == c) break;
            scanf("%d", &n);
            if (l > r) flag = 0;
        }
        if (n < l || n > r) flag = 0;
        if (flag) printf("Stan may be honest\n");
        else printf("Stan is dishonest\n");
    }
}