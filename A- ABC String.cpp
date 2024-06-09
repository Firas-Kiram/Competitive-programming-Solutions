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
	ll n = 3;
	vector <char> A = {'(' , ')'};
	for(int i = 0 ; i < (1 << n) ; i ++){
		vector <bool> setik(n , 0);
		for(int j = 0 ; j < n ; j ++){
			if(i & (1 << j)){
				setik[j] = 1;
			}else setik[j] = 0;
		}
		ll op = 0 , nx = 1;
		for(int j = 0 ; j < sz(s) && nx != 0; j += 1){
			char c = s[j];
			if(A[setik[c - 'A']] == '(') op += 1;
			else op -= 1;
			if(op < 0) nx = 0;
		}
		if(nx == 1 && op == 0) OUTRET("YES");
	}
	no
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