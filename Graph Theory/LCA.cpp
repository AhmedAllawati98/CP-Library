#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;
const int LG=__lg(N) + 1;
 
int n,q,T=1,up[N][LG],depth[N],in[N],out[N];
vector<int>g[N];
 
void dfs(int n,int p){
    in[n]=T;
    T++;
    up[n][0]=p;
    depth[n]=depth[p]+1;
    for(int i=1;i<LG;i++){
        up[n][i]=up[up[n][i-1]][i-1];
    }
    for(auto x:g[n]){
        if(x==p)continue;
        dfs(x,n);
    }
    out[n]=T-1;
}
 
int get_kth(int n,int k){
    for(int i=LG-1;i>=0;i--){
        if(k-(1<<i)>=0){
            n=up[n][i];
            k-=(1<<i);
        }
    }
    return n;
}
 
bool is_ancestor(int a,int b){
    return (a==0 || (in[b]>=in[a]&&out[b]<=out[a]));
}
 
int lca(int a,int b){
    if(is_ancestor(a,b))return a;
    if(is_ancestor(b,a))return b;
    for(int i=LG-1;i>=0;i--){
        if(!is_ancestor(up[a][i],b)){
            a=up[a][i];
        }
    }
    return up[a][0];
}
 
int dist(int a,int b){  // distance between two node 
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}
// node u lies on simple path between a,b if 
//dist(a,u)+dist(u,b)==dist(a,b)
 

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}