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
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
#define PI 3.1415926535897932384626433832795
const ll INF = 1000000000;
const ll MOD = 1000000007;
const ll M = 1e6 + 8432;
const int N= 2e5+10;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){

	ll n,k,mn = INF,mx=-INF;
	cin >> n >> k;
	vector <ll> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	ll ans = k + 1LL;
	for(int i=1;i<n;i++){
		ll x = v[i] - v[i - 1];
		ll y = k + 1LL;
		ans += min(x,y);
	}
	cout << ans << ln;
}

int main() {

    io();

    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
