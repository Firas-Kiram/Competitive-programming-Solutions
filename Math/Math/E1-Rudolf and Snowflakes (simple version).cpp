/** * * * * * * * * * * * * * * * **\
 *                                 *
 *   See its changed now you are   *
 *   not around i'm not the same,  *
 *    but! i hope you are proud,   *
 *       until we meet again       *
 *                                 *
\** * * * * * * * * * * * * * * * **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll INF = 1000000000;
const ll MOD = 998244353;
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

ll fpow(ll a, ll b){ 
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector <ll> A[10005];
void precount(ll n = 1e6){
	for(ll i = 2 ; i <= 10000 ; i ++){
		ll res = 1;
		for(ll j = 1 ; res <= n ; j ++){
			A[i].pb(res);
			res += fpow(i,j);
		}
	}
}



void solve() {
	ll n;cin >> n;
	for(int i = 2 ; i <= 10000; i ++){
		for(ll j = 2;j < sz(A[i]) ; j ++){
			if(A[i][j] == n) OUTRET("YES");
		}
	}
	no
}
 



int main() {
    io();
    precount();
    #ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
    int T = 1;	
	cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
