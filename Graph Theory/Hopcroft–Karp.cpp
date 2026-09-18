#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 500 + 9;

/*
maximumn matching on bibrtatie graph
A matching is a set of edges with no shared endpoint — each person is in at most one pair

matchL[u]  -->  u is a BOY (left).   Value = the GIRL he's matched to, or -1 if free.
matchR[v]  -->  v is a GIRL (right). Value = the BOY  she's matched to, or -1 if free.

*/
int n,m,k;
vector<int> g[N];
int matchL[N], matchR[N], dist[N];

bool bfs() {
    queue<int> q;
    bool found = false;
    for (int u = 1; u <= n; ++u) { // iterate over left group 
        if (matchL[u] == -1) { 
            dist[u] = 0;
            q.push(u); 
        }
        else dist[u] = -1;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            int w = matchR[v];
            if (w == -1) found = true;
            else if (dist[w] == -1) { dist[w] = dist[u] + 1; q.push(w); }
        }
    }
    return found;
}

bool dfs(int u) {
    for (int v : g[u]) {
        int w = matchR[v];
        if (w == -1 || (dist[w] == dist[u] + 1 && dfs(w))) {
            matchL[u] = v; matchR[v] = u;
            return true;
        }
    }
    dist[u] = -1;
    return false;
}

int maxMatching() {
    int res = 0;
    while (bfs())
        for (int u = 1; u <= n; ++u)
            if (matchL[u] == -1 && dfs(u)) ++res;
    return res;
}

void clean(){
    for(int i=1;i<N;i++){
        g[i].clear();
        matchL[i] = -1;
        matchR[i] = -1;
    }
}

void solve(){
    cin>>n>>m>>k;
    clean();
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    cout<<maxMatching()<<'\n';
    for(int i=1;i<=n;i++){
        if(matchL[i] != -1) {
            cout<<i<<" "<<matchL[i]<<'\n';
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}