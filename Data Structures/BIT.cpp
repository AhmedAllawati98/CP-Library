#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

ll fen[N];

void update(int i,int v){ 
    while(i<N){ 
        fen[i]+=v;
        i+=(i&(-i));
    }
}

ll get(int i){ 
    ll ans=0;
    while(i>0){ 
        ans+=fen[i];
        i=i-(i&(-i));
    }
    return ans;
}
// update(idx,val)


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}