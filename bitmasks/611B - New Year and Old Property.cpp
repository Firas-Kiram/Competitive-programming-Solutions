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

map <ll , bool> mp;
ll mx = 0;
void precount(){
	for(ll i = 0 ; i < 64 ; i += 1){
		ll nx = (1LL << i);
		nx += ((1LL << (i - 1)) - 1);
		mp[nx] = 1;
		for(ll j = i - 2; j >= 0 ; j --){
			nx += ((1LL << j));
			mp[nx] = 1;
		}
	}
}


void solve(){
	ll a,b;cin >> a >> b;
	ll tot = 0;
	// 2 pow x == (2 pow x - i) - 1 | i = x - 1 to 0
	for(auto it : mp){
		if(it.F <= b && it.F >= a) tot += 1;
	}
	cout << tot << ln;
}	


int main() {
    io();
    precount();
    int T = 1;
	//cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

