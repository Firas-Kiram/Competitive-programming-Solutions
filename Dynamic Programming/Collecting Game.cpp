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

void solve(){
	cin >> n;	
	vector <ll> A(n) , pre(n + 1, 0);
	vector <pi> v;
	map <ll ,ll> mp;
	for(int i=0;i<n;i++){
		cin >> A[i];
		v.pb({A[i] , i});
	}
	sort(all(v));
	for(int i=0;i<n;i++) mp[v[i].S] = i;
	sort(all(A));
	pre[0] = A[0];
	for(int i=1;i<n;i++){
		pre[i] = pre[i - 1] + A[i];
	}
	vector <ll> dp(n+1 , 0);
	dp[n - 1] = n - 1;
	for(int i=n - 2;i>=0;i--){
		dp[i] = (pre[i] < A[i + 1] ? i : dp[i + 1] );
	}
	ll ans[n];
	for(int i=0;i<n;i++) ans[i] = dp[mp[i]];
	for(auto it : ans) cout << it << ' ';
	cout << ln;
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
	 
    return 0;
}
