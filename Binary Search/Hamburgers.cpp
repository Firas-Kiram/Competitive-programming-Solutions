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
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
const ll INF = 1000000000;
const ll MOD = 1073741824;
const ll M = 1e6 + 8432;
const int N= 5e5+10;
const ll EPS = 1;
map <char , int> mp;
ll Nb ,Ns ,Nc ,Pb ,Ps ,Pc ,r;

bool good(ll x){
	ll reb = r;
	ll b = (x * mp['B']);
	b = max(b - Nb , 0LL);
	ll c = (x * mp['C']);
	c = max(c - Nc , 0LL);
	ll s = (x * mp['S']);
	s = max(s - Ns , 0LL);
	if(mp['B'])reb -= (ll)(b*Pb);
	if(mp['S'])reb -= (ll)(s*Ps);
	if(mp['C'])reb -= (ll)(c*Pc);
	return reb >= 0;
}

void solve(){
	string s;
	cin >> s >> Nb >> Ns >> Nc >> Pb >> Ps >> Pc >> r;
	for(auto it : s) mp[it]++;

	ll mn = INF;
	if(mp['B'] != 0) mn = min(mn ,Nb / mp['B']);
	if(mp['S'] != 0) mn = min(mn , Ns / mp['S']);
	if(mp['C'] != 0) mn = min(mn , Nc / mp['C']);
	if(mp['B'] != 0 && mn != 0)Nb -= (mn * mp['B']);
	if(mp['S'] != 0 && mn != 0)Ns -= (mn * mp['S']);
	if(mp['C'] != 0 && mn != 0)Nc -= (mn * mp['C']);
	ll l = 0 , r = 1 , ans = 0;
	while(good(r)) r*=2;
	while(l <= r){
		ll md = (l+r) / 2;
		if(good(md)){
			l = md+1;
			ans = md;
		}else{
			r = md-1;
		}
	}
	cout << ans  +  mn <<ln;
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
