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
	ll n;
	cin >> n;
	vector <vector <ll>> A(n ,vector<ll>(3));
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++)
			cin >> A[i][j];
	}
	vector <vector <ll>> dp(n+1,vector<ll>(3));
	for(int i=0;i<=n;i++){
		for(int j=0;j<3;j++){
			if(i == 0){
				dp[i][j] = A[i][j];
			}else{
				dp[i][j] = -1;
			}
		}
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			if(j == 0) dp[i][j] = max(dp[i - 1][1],dp[i - 1][2]) + A[i][j];
			if(j == 1) dp[i][j] = max(dp[i - 1][0],dp[i - 1][2]) + A[i][j];
			if(j == 2) dp[i][j] = max(dp[i - 1][0],dp[i - 1][1]) + A[i][j];
		}
	}
   	
   	cout << *max_element(all(dp[n - 1])) << ln;

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
