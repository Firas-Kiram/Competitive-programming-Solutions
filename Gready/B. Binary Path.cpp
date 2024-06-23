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
	vector <vector <ll>> v(2 , vector <ll>(n));

	auto get = [&](char c){return c - '0';};
	auto toChar = [&](ll c){return (char) c + '0';};

	for(int i = 0 ; i < 2 ; i += 1){
		for(int j = 0 ; j < n ; j += 1){
			char c;cin >> c;
			v[i][j] = get(c);
		}
	}
	string s = {};
	s.pb(toChar(v[0][0]));
	int idx = -1;
	for(int i = 1 ; i < n ; i ++){
		if(v[1][i - 1] < v[0][i]){
			idx = i - 1;
			for(int j = i - 1; j < n ; j ++) s.pb(toChar(v[1][j]));
			break;
		}else{
			s.pb(toChar(v[0][i]));
		}
		if(i == n - 1){
			idx = i;
			s.pb(toChar(v[1][i]));
		}
	}

	ll nx = 0 , tot = 0;
	for(int i = idx - 1 ; i >= 0 ; i --){
		if(v[1][i] == v[0][i + 1]) tot+=1;
		else break;
	}
	cout << s << ln << tot + 1 << ln;
	
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
