#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;


bool is_prime(ll n){
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        cout<<(is_prime(n) ? "Yes":"No")<<'\n';
    }
    
}