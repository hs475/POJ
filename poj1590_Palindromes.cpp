#include <stdio.h>
#include <cstring>
#include <map>

std::map <char, char> m;
char f[1000];

void init() {
    m['A'] = 'A';
    m['E'] = '3';
    m['H'] = 'H';
    m['I'] = 'I';
    m['J'] = 'L';
    m['L'] = 'J';
    m['M'] = 'M';
    m['O'] = 'O';
    m['S'] = '2';
    m['T'] = 'T';
    m['U'] = 'U';
    m['V'] = 'V';
    m['W'] = 'W';
    m['X'] = 'X';
    m['Y'] = 'Y';
    m['Z'] = '5';
    m['1'] = '1';
    m['2'] = 'S';
    m['3'] = 'E';
    m['5'] = 'Z';
    m['8'] = '8';
}

int ismirroed() {
    int l = 0, r = strlen(f) - 1;
    while (l <= r) {
        if (m.find(f[l]) == m.end() || m[f[l]] != f[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int ispalindrome() {
    int l = 0, r = strlen(f) - 1;
    while (l <= r) {
        if (f[l] != f[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int main() {
    init();
    int a, b;
    while (scanf("%s", f) != EOF) {
        a = ismirroed();
        b = ispalindrome();
        if (!b && !a) printf("%s -- is not a palindrome.\n", f);
        if (b && !a) printf("%s -- is a regular palindrome.\n", f);
        if (!b && a) printf("%s -- is a mirrored string.\n", f);
        if (a && b) printf("%s -- is a mirrored palindrome.\n");
        printf("\n");
    }

}