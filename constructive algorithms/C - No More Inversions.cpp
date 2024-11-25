#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll N = 2e5 + 100;
//    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    ll n , k;
    cin >> n >> k;
    ll inv = 0;
    if(n - k > 0){
        inv = (n - k) * (n - k + 1);
        inv -= (n - k);
    }
    ll idx = n;
    for(ll i = 0 ; i < k ; i ++){
        ll nx = 0 , ret = k - i - 1;
        if((ret * 1ll * ret) <= inv) idx = min(idx , i);
    }
    int kk = k;
    for(int i = 0 ; i < k ; i ++){
        if(idx <= i) cout << kk -- << ' ';
        else cout << i + 1 << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}   
