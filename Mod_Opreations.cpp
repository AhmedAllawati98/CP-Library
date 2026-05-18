#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;
const int mod = 1e9 + 7;

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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}