#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 1e6 + 100;


void solve() {
    ll n;cin >> n;
    vector <ll> v(n);
    for(int i = 0 ; i < n ; i ++) cin >> v[i];
    sort(v.begin() , v.end());
    ll res = 0;
    for(ll i = 0 ; i < n - 1 ; i ++) {
        res += ((v[i] - v[i + 1]) * 1ll * (v[i] - v[i + 1]));
    }
    cout << res << '\n';
}


signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
