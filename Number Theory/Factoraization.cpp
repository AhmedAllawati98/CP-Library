#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int>v;
    for(int i=1;i<=sqrt(n);i++){ 
        if(n%i==0){ 
            v.push_back(i);
            if(i!=sqrt(n))v.push_back(n/i);
        }
    }
    // not sorted
    
}