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

pair <ll , vector <ll>> calc(ll k , ll x , vector <ll> &a , vector <ll> &p){
	vector <ll> vis(sz(a) + 500 , 0) , res;
	pair <ll ,vector <ll>> A;
	ll nx = x , mx = a[x] , mxnv = 0 , idx = 0;
	while(!vis[nx] && idx < k){
		vis[nx] = 1;
		if(a[nx] > mx){
			mx = a[nx];
			mxnv = idx;
		}
		nx = p[nx];
		idx ++;
	}
	nx = x;
	for(int i = 0 ; i <= mxnv ; i += 1){
		A.S.pb(nx);
		nx = p[nx];
	}
	return A;
}


void solve(){
	ll n,k,b,s , mx = 0 , mxnv = 0;
	cin >> n >> k >> b >> s;
	vector <ll> a(n + 1, 0) , p(n + 1, 0) ;
	for(int i = 1 ; i <= n ; i += 1) cin >> p[i];
	for(int i = 1 ; i <= n ; i += 1) cin >> a[i];
	pair <ll , vector <ll>> setikB = calc(k , b , a , p);
	pair <ll , vector <ll>> setikS = calc(k , s , a , p);
	ll mxB = a[b] * k , mxS = a[s] * k , prefix = 0;
	ll nx = b;
	for(int i = 0 ; i < sz(setikB.S) ; i ++ ){
		nx = setikB.S[i];
		prefix += a[nx];
		mxB = max(mxB , prefix + (a[setikB.S[i]] * (k - (i + 1))));
	}
	prefix = 0 , nx = s;
	for(int i = 0 ; i < sz(setikS.S) ; i ++ ){
		nx = setikS.S[i];
		prefix += a[nx];
		mxS = max(mxS , prefix + (a[setikS.S[i]] * (k - (i + 1))));
	}
	if(mxB == mxS){
		cout << "Draw" << ln;
		return;
	}else{
		cout << (mxB > mxS ? "Bodya" : "Sasha") << ln;
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

