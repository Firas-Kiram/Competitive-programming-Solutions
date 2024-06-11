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
	int n,m;
	cin >> n >> m;
	vector <int> A[m + 5];
	for(int i = 0 ; i < m ; i ++){
		int c;cin >> c;
		for(int j = 0 ; j < c ; j ++){
			int x;cin >> x;
			A[i].pb(x);
		}
	}
	ll tot = 0;
	for(int i = 0 ; i < (1 << m) ; i ++){
		vector <int> a , vis(n + 1 , 0);
		for(int j = 0 ; j < m ; j ++){
			bool ok = (1 << j) & i;
			if(ok){
				a.pb(j);
			}
		}
		for(int j = 0 ; j < sz(a) ; j ++){
			for(int k = 0 ; k < sz(A[a[j]]) ; k ++){
				vis[A[a[j]][k]] = 1;
			}
		}
		int nx = 1;
		for(int j = 1; j <= n && nx ; j ++){
			if(!vis[j]) nx = 0;
		}
		tot += nx;
	}
	cout << tot << ln;
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
