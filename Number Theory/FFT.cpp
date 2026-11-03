#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N =  2 * 1e6 + 9;

const double PI = acos(-1);

void fft(vector<complex<double>>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        complex<double> wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; j++) {
                complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (auto& x : a) x /= n;
    }
}

vector<ll> multiply(vector<ll>& a, vector<ll>& b) {
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n, 0); fb.resize(n, 0);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = llround(fa[i].real());
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a;
    int mx = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        mx = max(mx,x);
    }
    vector<ll> cnt(mx + 1 , 0);
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    // all pair sum
    vector<ll> c = multiply(cnt,cnt);
    
}
