#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

// init p[i] = i before use 

int p[N],sz[N];

int find(int u){ 
    if(p[u] == u) return u;
    return p[u] = find(p[u]);
}  

void join(int a,int b){ 
    a = find(a);
    b = find(b);
    if(a != b){
      p[a] = b;        
      //sz[b] += sz[a];
    }   
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}