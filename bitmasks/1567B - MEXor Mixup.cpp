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
 
map <ll , ll> mp;

void precount(){
	ll n = 100000 * 3 + 500;
	ll x = 0;
	mp[0] = x;
	for(int i = 1 ; i < n ;i ++){
		x ^= i;
		mp[i] = x; 
	}
}
 
void solve(){
	ll a,b;
	cin >> a >> b;
	ll x = 0;
	x = mp[a];
	if(x == b) OUTRET(a + 2);
	ll y = mp[a - 1];
	cout << (y == b ? a : a + 1) << ln;
}	


int main() {
    io();
    int T = 1;
    precount();
    #ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
