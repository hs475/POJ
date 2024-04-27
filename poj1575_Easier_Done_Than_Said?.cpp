#include <stdio.h>
#include <cstring>

char a[25];

int vowel(char a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return 1;
    return 0;
}

int solve() {
    int flag = 0;
    for (int i = 0; i < strlen(a); ++i) {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            flag = 1;
            break;
        }
    }
    if (!flag) return 0;
    for (int i = 0; i + 2< strlen(a); ++i) {
        if (vowel(a[i]) == vowel(a[i+1]) && vowel(a[i]) == vowel(a[i+2])) return 0;
    }
    for (int i = 0; i + 1 < strlen(a); ++i) {
        if (a[i] != 'e' && a[i] != 'o' && a[i] == a[i+1]) return 0;
    }
    return 1;
}

int main() {
    while (scanf("%s", a) != EOF) {
        if (strcmp(a, "end") == 0) break;
        if (solve()) printf("<%s> is acceptable.\n", a);
        else printf("<%s> is not acceptable.\n", a);
    } 
}