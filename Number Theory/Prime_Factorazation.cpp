#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 9;

int n;

vector<int> pfact[N];
void method1(){ // you will just know the prime factor withot frequncy 
    for(int i = 2; i < N;i++){
        if(pfact[i].size() == 0){ // its mean this is prime 
            for(int j = i;j < N; j += i){
                pfact[j].push_back(i);
            }
        }
    }
}

void method2(){
   vector<int>v;
   for(int i=2;i*i<=n;i++){ 
       while(n%i==0){ 
           v.push_back(i);
           n=n/i;
       }
   } 
   if(n>1)v.push_back(n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}