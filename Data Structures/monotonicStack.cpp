#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e6 + 9;

int n,a[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> l(n+1,-1) , r(n+1,-1); // previous greater , next gratetr
    vector<int> st;
    for(int i=1;i<=n;i++){
        while(st.size() > 0 && a[i] > a[st.back()]) {
            st.pop_back();
        }
        if((int)st.size() > 0) {
            l[i] = st.back();
        }
        st.push_back(i);
    }
    st.clear();
    for(int i=n;i>=1;i--){
        while(st.size() > 0 && a[i] > a[st.back()]) {
            st.pop_back();
        }
        if((int)st.size() > 0) {
            r[i] = st.back();
        }
        st.push_back(i);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}