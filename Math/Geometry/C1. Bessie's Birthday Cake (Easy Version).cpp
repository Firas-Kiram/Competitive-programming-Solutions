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
	ll n,x,y;cin >> n >> x >> y;
	vector <ll> v(x , 0);
	map <ll , bool> vis;
	for(int i = 0 ; i < x ; i += 1){
		cin >> v[i];
	}
	if(n == x) OUTRET(n - 2);
	ll tot = x - 2;
	sort(all(v));
	for(int i = 1 ; i < sz(v) - 1; i += 1){
		if(v[i - 1] + 2 == v[i] && !vis[v[i] - 1]){
			tot += 1;
			vis[v[i] - 1] = 1;
		}
		if(!vis[v[i] + 1] && v[i] + 2 == v[i + 1]){
			tot += 1;
			vis[v[i] + 1] = 1;
		}
	}
	if(n - v.back() == 1 && !vis[n] && v[0] == 1) tot += 1;
	if(v[0] + 2 == v[1] && !vis[v[0] + 1]) tot += 1;
	if(v[0] != 1 && v[0] == 2 && vis[1]==false&&v.back() == n) tot += 1;
	cout << tot << ln;

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

