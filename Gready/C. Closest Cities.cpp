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
const ll MOD = 1073741824;
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
	ll n;cin >> n;
	vector <ll> v(n , 0) , pre(n , 0) , suf(n , 0);
	for(int i = 0 ; i < n ; i ++){
		cin >> v[i];
	}
	pre[1] = 1;
	for(int i = 1; i < n - 1; i += 1){
		if(abs(v[i - 1] - v[i]) > abs(v[i + 1] - v[i])){
			pre[i + 1] = pre[i] + 1;
		}else {
			pre[i + 1] = pre[i] + abs(v[i + 1] - v[i]);
		}
	}
	suf[n - 2] = 1;
	for(int i = n - 2; i >= 1 ; i --){
		if(abs(v[i - 1] - v[i]) > abs(v[i + 1] - v[i])){
			suf[i - 1] = suf[i] + abs(v[i - 1] - v[i]);
		}else{
			suf[i - 1] = suf[i] + 1;
		}
	}
	ll q;cin >> q;
	while(q --){
		ll a,b;cin >> a >> b;
		if(a < b){
			cout << pre[b - 1] - (a >= 1 ? pre[a - 1] : 0) << ln;
		}else{
			cout << suf[b - 1] - suf[a - 1] << ln;
		}
	}

}

int main() {
    io();
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
