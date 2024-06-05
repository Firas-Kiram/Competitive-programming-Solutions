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

pi precount(int i , int end){
	pi A = {0 , 0};
	ll mx = -1 , idx = end , tot = 0;
	for(int j = i ; j <= end ; j += 1){
		tot += (j * idx);
		mx = max(mx , j * idx);
		idx -= 1;
	}
	A = {tot , mx};
	return A;
}

void solve(){
	ll n , tot = 0;cin >> n;
	if(n == 2) OUTRET(2);
	vector <ll> v(n , 0) , pre(n , 0);
	for(int i = 0 ; i < n ; i += 1){
		v[i] = (i + 1) * (i + 1);
		tot += v[i];
	}
	ll ans = tot - (n * n);
	pre[0] = v[0];
	for(int i = 1 ; i < n ; i += 1){
		pre[i] += pre[i - 1] + v[i]; 
	}
	for(int i = 0 ; i + 2 <= n ; i += 1){
		pi A = precount(i + 2 , n);
		ans = max(ans , pre[i] + A.F - A.S);
	}
	cout << ans << ln;
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
