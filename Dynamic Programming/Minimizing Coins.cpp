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
const ll INF = 1000000000;
const ll MOD = 1073741824;
const ll M = 1e6 + 8432;
const int N= 5e5+10;
const ll EPS = 1;

void solve(){
	ll n,x;cin >> n >> x;
	vector <ll> v(n);
	for(int i=0;i<n;i++){cin >> v[i];}
	ll dp[x+1];
	for(int i=0;i<=x;i++) dp[i] = 1e9;
	dp[0] = 0;
	for(int i=1;i<=x;i++){
		for(auto it : v){
			if(i - it >= 0){
				dp[i] = min(dp[i] , dp[i - it]+1);
			}
		}
	}
	if(dp[x] == 1e9){
		cout << -1 << ln;
	}else{
		cout << dp[x] << ln;
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
