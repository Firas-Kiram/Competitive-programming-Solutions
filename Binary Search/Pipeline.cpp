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
ll n,k;

ll cum(ll x){
	return  (((x)*(x + 1)) / 2);
}

ll sum_(ll left , ll right){
	ll s = 0;
	if(left <= right){
		s = cum(right) - cum(left - 1);
	}
	return s;
}



void solve(){
	cin >> n >> k;
	if(n == 1)OUTRET(0);
	if(k >= n) OUTRET(1);
	k--;n--;
	if(n > cum(k))OUTRET(-1);
	ll l = 0,r = k;
	while(r - l > 1){
		ll md = (l + r) >> 1;
		ll s = sum_(md,k);
		if(s == n){
			OUTRET(k - md + 1);
		}else if(s > n){
			l = md ;
		}else{
			r = md ;
		}
	}
	cout << (k - r) + 2 <<ln;

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
