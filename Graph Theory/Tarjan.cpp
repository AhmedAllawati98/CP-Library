#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

int n,m,cur=1,T=1;
vector<int>g[N];
stack<int>s;
int idx[N],low[N],root[N],sz[N];
vector<int> comp[N];

void tarjan(int n){ 
    idx[n]=low[n]=T;
    T++;
    s.push(n);
    for(auto v:g[n]){ 
        if(idx[v]==-1){ 
         tarjan(v);
         low[n]=min(low[n],low[v]);
       }
       else if(root[v]==-1){ 
          low[n]=min(low[n],idx[v]);
       }
    }
    if(idx[n]==low[n]){ 
       while(s.top()!=n){ 
            root[s.top()]=cur;
            sz[cur]++;
            comp[cur].push_back(s.top());
            s.pop();
        }
        root[n]=cur;
        sz[cur]++;
        comp[cur].push_back(s.top());
        s.pop();
        cur++;
    }
}

int main()
{

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
    } 
    memset(low,-1,sizeof low);
    memset(idx,-1,sizeof idx);
    memset(root,-1,sizeof root);
    for(int i=1;i<=n;i++){ 
        if(idx[i]==-1){ 
            tarjan(i);
        }
    }

}