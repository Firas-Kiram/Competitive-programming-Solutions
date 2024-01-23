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
vector <ll> pre(M , 0) , p(M , 0);
void solve(){
	ll n,m,k;
	cin >> n >> m >> k; 
	vector <ll> v(n);
	for(auto &it : v) cin >> it;
	map<ll ,pair <pi , ll>> mp;
	ll c = 0; 
	while(m--){
		ll l , r , d;
		cin >> l >> r >> d;
		mp[c++] = {{l - 1, r - 1} , d};
	}
	while(k--){
		ll a,b;
		cin >> a >> b;
		pre[a - 1] += 1;
		if(b < sz(pre))pre[b] -= 1;
	}
	for(int i=1;i<sz(pre);i++){
		pre[i] += pre[i - 1];
	}
	for(int i=0;i<=sz(pre);i++){
		if(pre[i]>0){
			ll r = mp[i].F.S,l = mp[i].F.F,d = mp[i].S;
			//trace4(l,r,d,pre[i] *d);
			p[l] += (pre[i] * d);
			p[r + 1] -= (pre[i] * d);
		}
	}
	for(int i=1;i<sz(p);i++){
		p[i] += p[i - 1];
	}
	for(int i=0;i<n;i++){
		cout << v[i]  + p[i] << ' ' ;
	}
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
