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
#define mem(a, n) memset((a),n,sizeof (a))
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
const int N= 2e5+10;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
	ll n,k , ans = -1;cin >> n >> k;
	vector <pi> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].F;
	}
	for(int i=0;i<n;i++){
		cin >> v[i].S;
	}
	sort(all(v) , [&](pi a , pi b){
		return a.F < b.F;
	});
	vector<ll> h(n , 0);
	for(int i=0;i<n;i++){
		h[i] = v[i].F;
	}
	for(int i=n - 2;i >= 0 ; i--){
		v[i].S = min(v[i].S  , v[i + 1].S);
	}
	ll nx = 0;
	while(k > 0){
		ll idx = upper_bound(all(h) , k + nx) - h.begin();
		if(idx == n){yes;return;}
		ll mn = v[idx].S;
		nx += k;
		k -= mn;
	}
	no
}


int main() {
    io();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
