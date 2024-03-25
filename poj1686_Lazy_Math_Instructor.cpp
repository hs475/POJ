#include <stdio.h>
#include <cstring>
#include <string>
#include <stack>

int length;
char f[100];

int compare(char a, char b) {
    if ((a == '*' || a == '/') && (b == '+' || b == '-')) return 1;
    else return 0;
}

int cal(std::stack <char> s) {
    std::stack <int> f;
    int a, b;
    while (!s.empty()) {
        if (s.top() >= 'a' && s.top() <= 'z') f.push(s.top() - 'a' + 1);
        else {
            if (s.top() >= '0' && s.top() <= '9') f.push(int(s.top() - '0'));
            else {
                b = f.top();
                f.pop();
                a = f.top();
                f.pop();
                if (s.top() == '+') f.push(a + b);
                if (s.top() == '-') f.push(a - b);
                if (s.top() == '*') f.push(a * b);
                if (s.top() == '/') f.push(a / b);    
            }
        }
        s.pop();
    }
    return f.top();
}

int repolish_cal() {
    std::stack <char> s1, s2, res;
    for (int i = 0; i < strlen(f); ++i) {
        if (f[i] == ' ') continue;
        //printf("%c ", f[i]);
        if (f[i] == '+' || f[i] == '-' || f[i] == '*' || f[i] == '/') {
            while (1) {
                if (s1.empty() || s1.top() == '(' || compare(f[i], s1.top())) {
                    s1.push(f[i]);
                    break;
                }
                s2.push(s1.top());
                s1.pop();   
            }
        }
        else {
            if (f[i] != '(' && f[i] != ')') s2.push(f[i]);
            else {
                if (f[i] == '(') s1.push(f[i]);
                else {
                    while (s1.top() != '(') {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    s1.pop();
                }
            }
        }
    }
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    length = 0;
    while (!s2.empty()) {
        res.push(s2.top());
        s2.pop();
    }
    return cal(res);
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        gets(f);
        a = repolish_cal();
        gets(f);
        b = repolish_cal();
        if (a == b) printf("YES\n");
        else printf("NO\n");
    }
}

