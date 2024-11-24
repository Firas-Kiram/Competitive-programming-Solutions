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
const ll N = 1e5 + 100;
//    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> divisors(ll n){
    vector <ll> res;
    for(ll i = 1 ; i * i <= n ; i ++){
        if(n % i == 0){
            res.pb(i);
            if(n / i != i) res.pb(n / i);
        }
    }
    return res;
}

void solve() {
    ll a , b , c , d;
    cin >> a >> b >> c >> d;
    // y | (a*b)/gcd(a*b,x)
    vector <ll> aa = divisors(a) , bb = divisors(b);
    for(auto it : aa){
        for(auto itt : bb){
            ll x = it * 1ll * itt;
            ll xx = (a / x + 1) * x;
            if(xx > c) continue;
            ll k = (a * 1ll * b) / __gcd(a * 1ll * b , xx);
            ll y = (d / k) * k;
            if(y > b)
                return void(cout << xx << ' ' << y << '\n');
        }
    }
    cout << "-1 -1\n";
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
