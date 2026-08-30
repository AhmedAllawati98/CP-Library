#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 9;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // lower_bound / upper_bound require the vector to be sorted
    sort(a.begin(), a.end());

    int X = 1;

    // --------------------------------------------------
    // lower_bound(v.begin(), v.end(), X)
    // First position where value >= X
    // Number of values smaller than X
    // --------------------------------------------------
    int can = lower_bound(a.begin(), a.end(), X) - a.begin();

    // --------------------------------------------------
    // upper_bound(v.begin(), v.end(), X)
    // First position where value > X
    // Number of values smaller than or equal to X
    // --------------------------------------------------
    can = upper_bound(a.begin(), a.end(), X) - a.begin();

    // --------------------------------------------------
    // v.end() - upper_bound(...)
    // Number of values bigger than X
    // --------------------------------------------------
    int has = a.end() - upper_bound(a.begin(), a.end(), X);

    // --------------------------------------------------
    // v.end() - lower_bound(...)
    // Number of values bigger than or equal to X
    // --------------------------------------------------
    has = a.end() - lower_bound(a.begin(), a.end(), X);

    // --------------------------------------------------
    // Get iterator and index
    // --------------------------------------------------
    auto it1 = lower_bound(a.begin(), a.end(), 1);

    if (it1 != a.end()) {
        int a_idx = it1 - a.begin();

        cout << *it1 << " " << a_idx << '\n';
    }

    // --------------------------------------------------
    // Quick reference:
    //
    // lower_bound(X) -> first element >= X
    // upper_bound(X) -> first element >  X
    //
    // lower_bound(X) - begin()
    //     = number of elements < X
    //
    // upper_bound(X) - begin()
    //     = number of elements <= X
    //
    // end() - upper_bound(X)
    //     = number of elements > X
    //
    // end() - lower_bound(X)
    //     = number of elements >= X
    // --------------------------------------------------
}