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

  ll n;cin >> n;
	vector <ll> ans;
	vector <ll> A[n + 5];
	ll mx = 0;
	for(int i = 1 ; i <= n ;i += 1){
		for(int j = 1 ; j <= n ; j += 1){
			ll x;cin >> x;
			if(x == 1){
				A[i].pb(j);
			}
		}
	}

	for(int i = 0 ; i < (1 << n); i += 1){
		vector <ll> setik;
		for(int j = 0 ; j < n ; j += 1){
			if(i & (1 << j)){
				setik.pb(j + 1);
			}
		}
		bool ok = 1;
		for(int j = 0 ; j < sz(setik) && ok ; j += 1){
			for(int k = 0 ; k < sz(setik) && ok ; k += 1){
				bool check = 0;
				for(int o = 0 ; o < sz(A[setik[k]]) ; o += 1){
					if(setik[j] == A[setik[k]][o]) check = 1;
				}
				if(!check) ok = 0;
			}
		}
		if(ok && sz(setik) > mx){
				mx = sz(setik);
				ans = setik;
		}
	}
	cout << mx << ln;
	for(auto it : ans) cout << it << ' ';cout << ln;
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

