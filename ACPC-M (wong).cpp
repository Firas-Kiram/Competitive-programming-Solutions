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
const ll MOD = 998244353;
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
	ll n;cin >> n;
	vector <ll> v(n, 0) , a , l;
	for(int i = 0 ; i < n ; i ++){
		cin >> v[i];
	}
	if(n == 1) OUTRET(2);
	sort(all(v));
	for(int i = 0 ; i < n - 1 ; i ++){
		a.pb(abs(v[i] - v[i + 1]));
	}
	ll g = a[0];
	for(int i = 1 ; i < sz(a) ; i ++){
		g = gcd(g , a[i]);
	}
	if(g == 1) OUTRET(-1);
	for(int i = 0 ; i < sz(a) ; i ++){
		if(a[i] < g && a[i] % g == 0){
			l.pb(a[i]);
		}
	}
	if(l.size())
		sort(all(l));
	bool ok = 1;
	ll prev = g;
	if(l.size() && l[0] & 1) ok = 1;
	if(l.size()) g = min(g , l[0]);
	cout << (prev & 1 && ok ? g : 2) << ln;
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
