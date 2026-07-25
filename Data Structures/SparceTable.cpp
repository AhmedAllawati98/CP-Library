#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;
const int LG=__lg(N)+1;

int n,a[N],sp[N][LG];

void build(){
    for(int i=1;i<=n;i++){
        sp[i][0] = a[i];
    }
    for(int pw=1;pw<LG;pw++){
        for(int i = 1; i + (1<<pw) - 1 <= n;i++){
            sp[i][pw] = min(sp[i][pw - 1],sp[i + (1<<(pw - 1))][pw -1]);
        }
    }
}

int get(int l,int r){
    int len = __lg(r - l + 1);
    return min(sp[l][len],sp[r - (1<<len) + 1][len]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}