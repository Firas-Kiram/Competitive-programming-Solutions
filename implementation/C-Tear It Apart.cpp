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
	string s;cin >> s;
	map <char , vector <ll>> mp;
	int n = sz(s);
	char c = 0;
	bool ok = 0;
	for(ll i = 0 ; i < n ; i ++){
		if(c == s[i]){
			ok = 1;
			continue;
		}
		if(ok){
			mp[s[i - 1]].pb(-1LL);
			mp[s[i - 1]].pb(i - 1);
			ok = 0;
		}
		mp[s[i]].pb(i);
		c = s[i];
	}
	if(s.back() == s[n - 2]){
		mp[s.back()].pb(-1);
		mp[s.back()].pb(n - 1);
	}
	char ch = {};
	ll mn = INF;
	for(auto it : mp){
		ll mx = max(it.S[0] , n - (it.S[sz(it.S) - 1] + 1));
		for(int i = 0 ; i < sz(it.S) - 1; i ++){
			if(it.S[i + 1] != -1){
				if(it.S[i] == -1){
					if(i + 2 < sz(it.S)){
						mx = max(it.S[i + 2] - (it.S[i + 1] + 1) , mx);
					}
				}else mx = max(it.S[i + 1] - (it.S[i] + 1) , mx);
			}
		}
		mn = min(mx , mn);
	}
	if(mp.size() == 1) OUTRET(0);
	cout << ceil((double)log2(mn + 1)) << ln;
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


