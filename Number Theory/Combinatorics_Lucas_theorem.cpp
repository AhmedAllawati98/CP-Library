#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e6 + 5;
const int mod= 2e6 + 3;

ll fact[N],inv[N];

ll fp(ll b,ll p){  
    if(p==0) return 1;
    if(p&1) return (b*fp(b,p-1))%mod;
    return fp((b*b)%mod,p/2);
}

ll add(ll a,ll b){ 
    return ((a%mod)+(b%mod))%mod;
}

ll mul(ll a,ll b){ 
    return ((a%mod)*(b%mod))%mod;
}

ll sub(ll a,ll b){ 
    return ((a%mod)-(b%mod)+mod)%mod;
}

ll mod_inv(int a){
    return fp(a,mod-2);
}

ll dv(ll a,ll b){ 
    return mul(a,mod_inv(b));
} 

ll nCk_small(ll n, ll k) { 
    if (k < 0 || k > n) return 0;
    return ((fact[n] * inv[k]) % mod * inv[n - k]) % mod;  
} 

// Lucas' Theorem for large n, k
ll nCk(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    ll res = 1;
    while (n > 0 || k > 0) {
        ll ni = n % mod;
        ll ki = k % mod;
        res = (res * nCk_small(ni, ki)) % mod;
        n /= mod;
        k /= mod;
    }
    return res;
}

void pre() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < mod; i++) { 
        fact[i] = (fact[i - 1] * i) % mod;
    }
    // O(M) precomputation for inverse factorials
    inv[mod - 1] = fp(fact[mod - 1], mod - 2); 
    for (int i = mod - 2; i >= 1; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
}