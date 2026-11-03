#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5; 

ll fact[N], invFact[N];

ll fp(ll base, ll exp) { 
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mod_inv(ll a)   { return fp(a, MOD - 2); }
ll dv(ll a, ll b)    { return mul(a, mod_inv(b)); } 


ll nCk(ll n, ll k) { 
    if (k < 0 || k > n) return 0;
    return mul(fact[n], mul(invFact[k], invFact[n - k]));  
} 


ll nPk(ll n, ll k) { 
    if (k < 0 || k > n) return 0;
    return mul(fact[n], invFact[n - k]);  
}

void pre() {
    fact[0] = 1;
    invFact[0] = 1;

    for (int i = 1; i < N; i++) { 
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[N - 1] = mod_inv(fact[N - 1]); 

    for (int i = N - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
}