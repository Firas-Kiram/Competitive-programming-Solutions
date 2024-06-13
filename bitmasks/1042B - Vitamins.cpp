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

void solve(){
	ll n;cin >> n;
	vector <ll> v(32 , INF) , A = {1 , 2 , 3 , 4 , 5 , 6 , 7};
	for(int i = 0 ; i < n ; i += 1){
		ll x = 0;
		ll c;cin >> c;
		string s;cin >> s;
		for(char c : s){
			int val = get(c);
			x += (1 << val);
		}
		if(c < v[x]){
			v[x] = c;
		}
	}

	ll m = 7 , mn = INF;
	for(int i = 0 ; i < (1 << m) ; i++){
		vector <int> a;
		for(int j = 0 ; j < m ; j ++){
			bool ok = (1 << j) & i;
			if(ok){
				a.pb(j);
			}
		}
		ll res = 0 , k = 0;
		for(int j = 0 ; j < sz(a) ; j += 1){
			k += v[A[a[j]]];
			res |= A[a[j]];
		}
		if(res == 7){
			mn = min(mn , k);
		}
	}
	cout << (mn == INF ? -1 : mn) << ln;
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
