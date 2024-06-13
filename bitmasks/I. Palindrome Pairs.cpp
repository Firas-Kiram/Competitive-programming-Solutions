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

ll get(char c){
	return c - 'a';
}

bool isPowerOfTwo(ll n){
	return !(n & (n - 1));
}

void solve(){
	ll n;cin >> n;
	vector <ll> a(n , 0);
	for(int i = 0 ; i < n ; i += 1){
		string s;cin >> s;
		vector <ll> setik(26 , 0);
		for(int j = 0 ; j < sz(s) ; j += 1){
			ll x = get(s[j]);
			setik[x] ++;
		}
		ll nx = 0;
		for(ll j = 0 ; j < 26 ; j += 1){
			if(setik[j] & 1){
				nx += (1LL << j);
			}else nx += 0;
		}
		a[i] = nx;
	}
	ll ans = 0;
	map <ll , ll> mp;
	for(int i = 0 ; i < sz(a) ; i += 1){
		ans += mp[0 ^ a[i]];
		for(ll j = 0 ; j <= 26 ; j ++){
			ll k = (1LL << j) ^ a[i];
			ans += mp[k];
		}
		mp[a[i]] += 1;
		ll x = 0 ^ a[i];
	}
	cout << ans << ln;
}	

int main() {
    io();
    
    int T = 1;
    #ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	//cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
