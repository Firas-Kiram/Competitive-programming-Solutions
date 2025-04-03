#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll N = 1e6 + 100;
vector < ll > spf;

void pre(){
    int n = 15000100;
    spf = vector < ll > (n + 1 , {});
    iota(spf.begin() , spf.end() , 0);
    for(ll i = 2 ; i <= n ; i ++){
        if(spf[i] != i) continue;
        for(ll j = i ; j <= n ; j += i)
            spf[j] = min(spf[j] , i);
    }
}

set <ll> get(ll n) {
    set <ll> s;
    while(n > 1) 
        s.insert(spf[n]) , n /= spf[n];
    return s;
}

void solve() {
    ll n , mx = 0 , g = 0; cin >> n;
    vector <ll> v(n);
    for(int i = 0 ; i < n ; i ++) cin >> v[i] , mx = max(mx , v[i]) , g = gcd(v[i] , g);
    vector < ll > cnt(mx + 5 , {});
    for(int i = 0 ; i < n ; i ++){
        set <ll> ret = get(v[i] / g);
        for(auto to : ret) cnt[to] ++ ;
    }
    vector < ll > a;
    for(int i = 1 ; i <= mx ; i ++) {
        if(!cnt[i]) continue;
        a.pb(cnt[i]);
    }
    ll res = INT_MAX;
    sort(a.begin() , a.end());
    for(int i = a.size() - 1 ; i >= 0 ; i -- ){
        res = min(res ,n - a[i]);
    }
    cout << (res == INT_MAX ? -1 : res) << '\n';
}


signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    ll T = 1;
    // cin >> T;
    pre();
    while (T--) {
        solve();
    }
    return 0;
}
