#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 5e5 + 9;
const int LG = 20;
const char Ch = 'A';

int n, T = 1;
int up[N][LG], depth[N], in[N], out[N];
vector<int> g[N];
string s;

// Hashing Variables (Double Hash)
int base[2] = {31, 37};
int mod[2] = {(int)1e9+7, (int)1e9+9};
ll H_down[2][N]; // Hash from Root to Node
ll H_up[2][N];   // Hash from Node to Root
ll pw[2][N], inv_pw[2][N];


ll power(ll b, ll p, ll m) {
    ll res = 1;
    b %= m;
    while (p > 0) {
        if (p % 2 == 1) res = (res * b) % m;
        b = (b * b) % m;
        p /= 2;
    }
    return res;
}

// Precompute Powers and their Inverses
void precompute_hashes() {
    pw[0][0] = pw[1][0] = 1;
    inv_pw[0][0] = inv_pw[1][0] = 1;
    
    ll inv0 = power(base[0], mod[0]-2, mod[0]);
    ll inv1 = power(base[1], mod[1]-2, mod[1]);
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            pw[j][i] = (pw[j][i-1] * base[j]) % mod[j];
            inv_pw[j][i] = (inv_pw[j][i-1] * (j == 0 ? inv0 : inv1)) % mod[j];
        }
    }
}


void dfs(int u, int p) {
    in[u] = T++;
    up[u][0] = p;
    depth[u] = depth[p] + 1;

    int val = s[u-1] - Ch + 1; 

    for(int j = 0; j < 2; j++) {
        // Root DOWN to u
        H_down[j][u] = (H_down[j][p] * base[j] + val) % mod[j];
        // u UP to Root (notice val is multiplied by the base power based on depth)
        H_up[j][u] = (val * pw[j][depth[u]-1] + H_up[j][p]) % mod[j];
    }

    for(int i = 1; i < LG; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for(int v : g[u]) {
        if(v != p) dfs(v, u);
    }
    out[u] = T - 1;
}

bool is_ancestor(int a, int b) {
    return (a == 0 || (in[b] >= in[a] && out[b] <= out[a]));
}

int lca(int a, int b) {
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;
    for(int i = LG-1; i >= 0; i--) {
        if(!is_ancestor(up[a][i], b)) {
            a = up[a][i];
        }
    }
    return up[a][0];
}

void clean() {
    T = 1;
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

pair<ll, ll> get_path_hash(int u, int v) {
    int c = lca(u, v);
    pair<ll, ll> res;
    
    if(c == u) { 
        // Path goes strictly DOWN
        int len = depth[v] - depth[u] + 1;
        for(int j = 0; j < 2; j++) {
            ll val = (H_down[j][v] - H_down[j][up[u][0]] * pw[j][len]) % mod[j];
            if(val < 0) val += mod[j];
            if(j == 0) res.first = val; else res.second = val;
        }
    } 
    else if(c == v) { 
        // Path goes strictly UP
        for(int j = 0; j < 2; j++) {
            ll val = (H_up[j][u] - H_up[j][up[v][0]]) % mod[j];
            val = (val * inv_pw[j][depth[v]-1]) % mod[j]; // Shift polynomial down
            if(val < 0) val += mod[j];
            if(j == 0) res.first = val; else res.second = val;
        }
    } 
    else { 
        // Path goes UP to LCA, then DOWN to v
        int len_down = depth[v] - depth[c];
        for(int j = 0; j < 2; j++) {
            // Extract UP part (from u to c)
            ll up_val = (H_up[j][u] - H_up[j][up[c][0]]) % mod[j];
            up_val = (up_val * inv_pw[j][depth[c]-1]) % mod[j];
            if(up_val < 0) up_val += mod[j];

            // Extract DOWN part (from child of c to v)
            ll down_val = (H_down[j][v] - H_down[j][c] * pw[j][len_down]) % mod[j];
            if(down_val < 0) down_val += mod[j];

            // Combine them
            ll val = (up_val * pw[j][len_down] + down_val) % mod[j];
            if(j == 0) res.first = val; else res.second = val;
        }
    }
    return res;
}

pair<ll,ll> cal_Hash(string s){
    vector<ll>v;
    for(int i=0;i<2;i++){
        ll val=0;
        for(auto x:s){
            val=(val*base[i]+(x-Ch+1))%mod[i];
        }
        v.push_back(val);
    }
    return {v[0],v[1]};
}

void solve() {
    int m;
    cin >> n >> m;
    clean();
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> s;
   
    H_down[0][0] = H_down[1][0] = 0;
    H_up[0][0] = H_up[1][0] = 0;
    
    dfs(1, 0);
    
    vector<pair<ll, ll>> vv;
    while(m--) {
        string ss;
        cin>>ss;
        vv.push_back(cal_Hash(ss));
    }    
    sort(vv.begin(), vv.end());
    
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        
        pair<ll, ll> h = get_path_hash(u, v);
        bool x = binary_search(vv.begin(), vv.end(), h);
        cout<<(x ? "YES":"NO")<<'\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precompute_hashes(); 
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}