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

void solve(){
	int n;cin >> n;
	vector <ll> v(n , 0);
	map <ll ,vector <ll>> A;
	map <ll , ll> count;
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	sort(all(v));
	for(int i=0;i<n;i++){
		count[v[i]] += 1;
		A[count[v[i]]].pb(v[i]);
	}
	int tot = 0;
	for(auto it : A){
		int nx = sz(it.S);
		bool ok = 1;
		for(int i=1;i<nx&&ok;i++){
			if(it.S[i] != it.S[i - 1] + 1){
				tot += 1;
			}

		}
		tot += 1;
	}
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
