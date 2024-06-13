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
	ll nx = count(all(s) , '?') , mn = 10;
	for(int i = 0 ; i < (1 << nx) ; i ++){
		vector <bool> a;
		for(int j = 0 ; j < nx ; j ++){
			bool ok = (1 << j) & i;
			if(ok){
				a.pb(1);
			}else a.pb(0);
		}
		string m = s;
		//1000101001
		ll idx = 0 , k = 0 ;
		ll t1 = 0 ,t2 = 0;
		for(int j = 0 ; j < sz(m) ; j += 1){
			if(m[j] == '?'){
				m[j] = (a[idx] ? '1' : '0');
				idx += 1;
			}
		}
		for(int j = 0 ; j < sz(m) ; j ++){
			if(j & 1){
				if(m[j] == '1') t2 ++;
			}else{
				if(m[j] == '1') t1 ++;
			}
			ll p = 10 - j - 1;
			ll f = 0;
			if(t1 > t2 ){
				if(t1 > t2 + (p / 2 + (p & 1)))
					mn = min(mn , j + 1LL);
			}else{
				if(t1 + ( p / 2 ) < t2)
					mn = min(mn , j + 1LL);
			}
		}
	}	
	cout << mn << ln;
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
