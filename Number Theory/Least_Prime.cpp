#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

int lp[N];
vector<int> pr;

void f() {
    for (int i = 2; i < N; ++i){
        if (lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i *1ll* pr[j] < N; ++j){
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]){
                break;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}