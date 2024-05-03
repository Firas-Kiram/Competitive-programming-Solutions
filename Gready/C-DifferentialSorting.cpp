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
const int N= 2e5+10;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

bool check(vector <ll>&v){
	int n = sz(v);
	bool ok = 1;
	for(int i=0;i<n-1&&ok;i++){
		if(v[i] > v[i + 1]) ok = 0;
	}
	return ok;
}

void solve(){
	int n;cin >> n;
	vector <ll> v(n, 0);
	vector <pi> A(n);
	vector <pair <pi , ll>> setik;
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	bool ok = check(v);
	if(ok) OUTRET(0);
	pi mx = {-INF, n}, mn = {INF , n} , lst = {-INF , n};
	for(int i=n - 1;i >= 1 ; i --){
		if(i + 1 < n && lst.F < v[i + 1]){
			lst = {v[i + 1] , i + 1};
		}
		if(mn.F >= v[i] && i < mx.S){
			mn = {v[i] , i};
			mx = lst;
		}
		if(lst.S > mn.S && lst.F > mx.F){
			mx = lst;
		}
		A[i - 1] = {mn.S , mx.S};
	}

	for(int i=0;i<n-2;i++){
		if(A[i].F >= n || A[i].S >= n) continue;
		ll ans = v[A[i].F] - v[A[i].S];
		if(ans < v[i]){
			v[i] = ans;
			setik.pb({{A[i].F  + 1, A[i].S + 1} , i + 1});
		}
	}
	ok = check(v);
	if(!ok) OUTRET(-1);
	cout << sz(setik) << ln;
	for(auto it : setik){
		cout << it.S << ' ' <<  it.F.F << ' ' << it.F.S << ' '  << ln;
	}
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

