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

void solve(){
	ll n , s = 0;cin >> n;
	vector <pi> v(n);
	map <ll , ll> vis;
	for(int i = 0 ; i < n ; i += 1){
		cin >> v[i].F;
		v[i].S = i + 1;
		vis[v[i].F] += 1;
		s += v[i].F;
	}
	sort(all(v));
	set <ll> st;
	ll mn = v[0].F , nx = v[n - 2].F; // nx is the prev max
	if(s - v.back().F - nx == nx){
		for(int i = 0 ; i < n ; i += 1){
			if(v[i].F == v.back().F) st.insert(v[i].S);
		}
	}
	ll y = abs((s - v.back().F) - v.back().F);
	bool check = 1;
	if(y == v.back().F){
		if(vis[y] > 1) check = 1;
		else check = 0;
	}
	if(s - v.back().F >= v.back().F && vis[y] && check){
		for(int i = 0 ; i < n ; i += 1){
			if(v[i].F == abs((s - v.back().F) - v.back().F)){
				st.insert(v[i].S);
			}
		}
	}

	cout << sz(st) << ln;
	for(auto it : st) cout << it << ' ';cout << ln;
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

