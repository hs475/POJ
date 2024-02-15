#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double LD;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
ll mil[] = {2,325,9375,28178,450775,9780504,1795265022};

ll quickpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b%2) res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

ll qmul(ll a, ll b, ll n) {
    ll res = 0;
    while (b) {
        if (b%2) res = (res + a) % n;
        a = a * 2 % n;
        b /= 2;
    }
    return res;
}

ll fastmod(ll a, ll d, ll n) {
    ll res = 1;
    a %= n;
    while (d) {
        if (d%2) res = qmul(res, a, n);
        a = qmul(a, a, n);
        d /= 2;
    }   
    return res % n; 
}

ll f(ll x, ll c, ll n) {return ((x * x) + c) % n;}

ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);} 

ll pollard_rho(ll n) {
    ll c = rand() % (n - 1) - 1, d;
    ll t = f(0, c, n), r = f(f(0, c, n), c, n);
    while (t!=r) {
        if (t>r) d = gcd(t-r, n);
        else d = gcd(r-t, n);
        if (d>1) return d;
        t = f(t, c, n);
        r = f(f(r, c, n), c, n);
    }
    return n;
}

int millarTest(ll n) {
    int flag = 0;
    ll r = 0, d = n - 1;
    while ((d)%2==0) {
        r++;
        d /= 2;
    }
    for (int i=0; i<7&&mil[i]<n-2; ++i) {
        flag = 0;
        ll tmp = fastmod(mil[i], d, n);
        if (tmp==1||tmp==n-1) continue;
        for (int t=1; t<r; ++t) {
            tmp = qmul(tmp, tmp, n);
            if (tmp==n-1) {
                flag = 1;
                break;
            }
        }
        if (flag==0) {
            return 0;
        }
    }
    return 1;
}

void solve(int n) {
    ll k;
    vector <ll> vec;
    int v;
    for (int i=0; i<sizeof(prime)/sizeof(prime[0]); ++i) {
        v = prime[i];
        if (v>n) break;
        ll t = quickpow(2, v);
        t--;
        if (!millarTest(t)) {
            while (1) {
                k = pollard_rho(t);
                vec.push_back(k);
                t /= k;
                if (millarTest(t)) {
                    vec.push_back(t);
                    break;
                }
            }
            sort(vec.begin(), vec.end());
            for (int i = 0; i<vec.size()-1; ++i) printf("%lld * ", vec[i]);
            printf("%lld = %lld = ( 2 ^ %d ) - 1", vec[vec.size()-1], quickpow(2, v) - 1, v);
            printf("\n");
            vec.clear();
        }
    }
}


int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}
