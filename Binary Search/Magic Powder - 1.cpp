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
const ll MOD = 1e9 + 7;
const ll M = 1e6 + 8432;
const int N= 5e5+10;
vector <ll> A(M , 0) , B(M , 0);
ll n , k ;

bool can(ll md){
	ll x = k;
	for(int i=0;i<n;i++){
		ll a = B[i] / A[i];
		if(a < md){
			ll b = A[i] * md;
			x -= abs(b - B[i]);
		}
		if(x < 0) return 0;
	}
	return 1;
}

void solve(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	ll l = 0 , r = 1, ans = 0;
	while(can(r)) r*=2;
	while(l <= r){
		ll md = (l + r)>>1;
		if(can(md)){
			l = md + 1;
			ans = md;
		}else{
			r = md - 1;
		}
	}
	cout << ans <<ln;
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
