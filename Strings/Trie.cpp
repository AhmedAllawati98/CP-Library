#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 9;

// dont forget to do trie.push_back(node()) before start 

int n,q;
struct node {
    int ch[26];
    int cnt;

    node(){
        cnt = 0;
        for(int i=0;i<26;i++){
            ch[i] = -1;
        }
    }
};
vector<node> trie;

void insert(string s){
    int cur = 0;
    for(int i=0;i<s.size();i++){
        int idx = s[i] - 'a';
        if(trie[cur].ch[idx] == -1) {
            trie[cur].ch[idx] = trie.size();
            trie.push_back(node());
        }
        cur = trie[cur].ch[idx];
        trie[cur].cnt++;
    }
}

int query(string s){
    int cur = 0;
    for(int i=0;i<s.size();i++){
        int idx = s[i] - 'a';
        if(trie[cur].ch[idx] == -1){
            return 0;
        }
        cur = trie[cur].ch[idx];
    }
    return trie[cur].cnt;
}

void solve(){
    cin>>n>>q;
    trie.push_back(node());
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    while(q--){
        string s;
        cin>>s;
        cout<<query(s)<<'\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}