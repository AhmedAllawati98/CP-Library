#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n,m;
vector<int> g[N];
int col[N];

bool dfs(int n){ 
    for(auto x:g[n]){ 
        if(col[x]==col[n])return false;
        if(col[x]==0){ 
           col[x]=3-col[n];
           if(dfs(x)==false) return false;       
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
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int c = 0;
    for(int i=1;i<=n;i++){
        if(col[i] == 0){
            col[i] = 1;
            if(!dfs(i)) {
                cout<<"Not bipartite"<<'\n';
                return 0;
            }
            c++;
        }
    }
    cout<<"bipartite"<<'\n';
}