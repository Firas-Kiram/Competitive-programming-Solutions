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
 
bool isPowerOfTwo(ll num) {
	return (num & num - 1) == 0;
}

void solve(){
	vector <ll> v , a;
	ll n;cin >> n;
	// if(n == 3) OUTRET("2 0 1");
	ll mx = -INF;
	for(ll i = 1 ; i < n ; i ++){
		if(isPowerOfTwo(i)) mx = max(mx ,i);
		if(i + 1 < n){
			if(isPowerOfTwo(i + 1)){
				v.pb(i);
			}else a.pb(i);
		}else a.pb(i);
	}
	for(auto it : v) cout << it << ' ';
	sort(all(a) , [&](ll a,ll b){
		return a > b;
	});
	for(int i = 0 ; i < sz(a) ; i ++) {
		if(a[i] < mx) cout << a[i] << ' ';
	}
	cout << 0 << ' ' ;
	for(int i = mx ; i < n ; i ++ ) cout << i << ' ';cout << ln;

}	


int main() {
    io();
    int T = 1;
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
