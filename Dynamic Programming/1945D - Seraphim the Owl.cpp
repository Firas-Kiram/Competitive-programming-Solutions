#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll INF = 1000000000;
const ll MOD = 1073741824;
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

void solve(){
	ll n , m;cin >> n >> m;
	vector <ll> dp(n + 1, 0) , a(n , 0) , b(n , 0);
	for(int i = 0 ; i < n ; i += 1){
		cin >> a[i];
	}
	for(int i = 0 ; i < n ; i ++){
		cin >> b[i];
	}
	dp[n] = 0;
	dp[n - 1] = min(a[n - 1] , b[n - 1]);
	for(int i = n - 1 ; i >= 0 ; i --){
		dp[i] = dp[i + 1] + min(a[i] , b[i]);
	}
	ll ans = LLONG_MAX;
	for(int i = n - 1 ; i >= 0 ; i --){
		if(i <= m - 1){
			ans = min(ans , dp[i + 1]+a[i]);	
		}
	}
	cout << ans << ln;
}

int main() {
    io();
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
