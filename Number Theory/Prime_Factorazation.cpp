#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

vector<int> pfact[N];
void f1(){ // you will just know the prime factor withot frequncy 
    for(int i = 2; i < N;i++){
        if(pfact[i].size() == 0){ // its mean this is prime 
            for(int j = i;j < N; j += i){
                pfact[j].push_back(i);
            }
        }
    }
}

void f(int x){
   vector<int>v;
   for(int i=2;i*i<=x;i++){ 
       while(x%i==0){ 
           v.push_back(i);
           x=x/i;
       }
   } 
   if(x>1)v.push_back(x);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}