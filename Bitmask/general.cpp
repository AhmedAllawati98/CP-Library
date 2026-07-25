#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

int n;

bool mnwr(ll x,int bit){
    if(x & ((ll)1<<bit)) return true;
    return false;
}

void all_subset(){
    for(int mask = 0;mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if(mask & (1<<i)){
                cout<<i<<" ";
            }
        } 
    }
}

int count_num_of_one(ll x){
    int k = __builtin_popcountll(x);
    return k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}