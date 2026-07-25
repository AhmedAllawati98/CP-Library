#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

bool prime[N];
vector<int> pr;

void seiv(){
   prime[0] = prime[1] = 0;
   for(int i = 2;i <= N - 3; i++) prime[i] = true;
   for(int i = 2; i <= N - 3;i++){ 
       if(prime[i] == true){
           pr.push_back(i);
           for(ll j = (ll)i * i; j <= N - 3; j += i){ 
               prime[j] = false;
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