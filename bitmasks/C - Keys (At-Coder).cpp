#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
void watch(vector<ll>v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 100;

void solve() {
    ll n , m , k;cin >> n >> m >> k;
    vector <ll> v[m];
    vector <bool> check(m , false);
    for(int i = 0 ; i < m ; i ++){
        ll c;cin >> c;
        for(int j = 0 ; j < c ; j ++){
            ll x;cin >> x;
            v[i].pb(x);
        }
        char ch;cin >> ch;
        check[i] = (ch == 'o');
    }
    ll res = 0;
    for(int i = 0 ; i < (1ll << n) ; i ++){
        vector <bool> key(n + 1, false);
        for(int j = 0 ; j < n ; j ++){
            bool ok = i & (1ll << j);
            if(ok) key[j + 1] = 1;
        }
        bool ok = 1;
        for(int j = 0 ; j < m ; j ++){
            ll cnt = 0;
            for(auto it : v[j]){
                if(key[it]) cnt ++ ;
            }
            bool p = (cnt >= k);
            if(p != check[j]) ok = 0;
        }
        res += ok ;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}   
