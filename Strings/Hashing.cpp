#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 9;
const char base_char = 'A'; // dont forgot to change it 

int base[2]={31,37};
int mod[2]={(int)1e9+7,(int)1e9+9};
ll H[2][N];
ll pw[2][N];
 
void Hash_pref(int n,string s){
    pw[0][0]=pw[1][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            H[j][i]=(H[j][i-1]*base[j]+(s[i-1]-base_char+1))%mod[j];
            pw[j][i]=pw[j][i-1]*base[j]%mod[j];
        }
    }
}
 
pair<ll,ll> sub_Hash(int l,int r){
    ll h0 = H[0][r] - (H[0][l-1] * pw[0][r-l+1] % mod[0]);
    if(h0 < 0) h0 += mod[0];
    
    ll h1 = H[1][r] - (H[1][l-1] * pw[1][r-l+1] % mod[1]);
    if(h1 < 0) h1 += mod[1];
    
    return {h0, h1};
}
 
pair<ll,ll> cal_Hash(string s){
    vector<ll>v;
    for(int i=0;i<2;i++){
        ll val=0;
        for(auto x:s){
            val=(val*base[i]+(x-base_char+1))%mod[i];
        }
        v.push_back(val);
    }
    return {v[0],v[1]};
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}