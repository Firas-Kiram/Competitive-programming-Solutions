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
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
#define ON(n, k) ((n) | (1 << (k)))
#define OFF(n, k) ((n) & ~(1 << (k)))
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}	
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define PI 3.1415926535897932384626433832795
const ll INF = 1000000000;
const ll MOD = 1000000007;
const ll M = 1e6 + 8432;
const int N= 2e5+10;
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}


ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

inline void print_vector(vector<ll> &a)
{
    for (auto &x : a)
        cout << x << ' ';
    cout << ln;
}

vector<ll> factor(ll x){
    vector<ll> ret ;
    for(int j = 1 ; j*j<=x ; j++){
        if(x%j) continue;
        ret.pb(j) ;
        if(x/j != j) ret.pb(x/j) ;
    }
    return ret ;
}

set <ll> prime_factor(ll n){
	set <ll> res;
	for(int i=2;i * i<=n;i++){
		while(n % i == 0){
			res.insert(i);
			n/=i;
		}
	}
	if(n > 1)
		res.insert(n);
	return res;
}

bool prime[15000105]; 
void sieve(ll n) { 
	for (ll i = 0; i <= n; i++) prime[i] = 1;
	 	for (ll p = 2; p * p <= n; p++) { 
			if (prime[p] == true) { 
		 	for (ll i = p * p; i <= n; i += p) 
				prime[i] = false; 
			} 
		}	 
	  prime[1] = prime[0] = 0;
} 


void solve(){

	ll n;
	cin >> n;
	sieve(n);
	vector<ll> ans;
	for(int i=2;i<=n;i++){
		vector <ll> a = factor(i);
		vector <ll> b = factor(i * 2);
		ll p = sz(a) - 2;
		ll q = sz(b) - 2;
		bool check = false;
		if((i * 2) <= n){
			if(q > p){
				check = true;
			}
		}else check = true;
		set <ll> s;
		for(auto it : a){
			if(!prime[it]){
				set <ll> temp = prime_factor(it);
				s.insert(all(temp));
			}else s.insert(it);
		}
		if(sz(s) < 2) check = false;
		// if((i * 2) <= n){
		// 	check = (sz(b) > sz(a));
		// }
		if(p >= 2 && check){
			continue;
		}
		ans.pb(i);
	}
	cout << sz(ans) << ln;
	print_vector(ans);
}


int main() {
 
    io();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
	 
    return 0;
}
