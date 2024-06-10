#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define dbg(x) cout <<#x<<": "<<x<< ln;
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
#define PI 3.1415926535897932384626433832795
const ll INF = 1000000000;
const ll MOD = 1000000007;
const ll M = 1e6 + 8432;
const ll N = 1000000000000;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

ll get(ll k , ll j){
	if(j <= k) return (ll)(j * (j + 1)) / 2;
	ll s = (ll)(k * (k + 1)) / 2;
	ll idx = j - k;
	idx = (k- idx);
	return (ll)(s + (s - k) - (((ll)idx - 1LL)*((ll)idx)) / 2);
}

bool can(ll x , ll k ,ll md){
	ll s = get(k , md);
	return x >= s;
}

void solve(){
	ll k , x;cin >> k >> x;
	ll s = (k * (k + 1)) - k;
	ll nx = 2 * k - 1;
	if(s <= x) OUTRET(nx);
	ll l = 0 , r = nx , ans = 0;
	while(r - l > 1){
		ll md = (l + r) / 2;
		if(can(x , k , md)){
			l = md;
			ans = md;
		}else r = md;
	}
	if(get(k , ans) < x) ans ++;
	cout << ans << ln;
}	


int main() {
    io();
    int T = 1;
    #ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
