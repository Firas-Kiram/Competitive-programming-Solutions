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
const ll MOD = 1e9 + 7;
const ll M = 1e6 + 8432;
const ll N = 2e5 + 2000;
 
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

ll dp[M];
ll path[M];
ll n;

void solve() {
    cin >> n;
    if(n == 1) {
        cout << 0 << ln;
        cout << 1 << ln;
        return;
    }
    for(int i = 0 ; i <= n ; i ++) dp[i] = INF;
    for(int i = 0 ; i <= n ; i ++) path[i] = i;
    dp[n] = 0;
    for(int i = n ; i >= 1 ; i --){
        if(i % 3 == 0 && i / 3 >= 1 && dp[i] + 1 < dp[i / 3] ){
            dp[i / 3] = dp[i] + 1;
            path[i / 3] = i;
        }
        if(i % 2 == 0 && i / 2 >= 1 && dp[i] + 1 < dp[i / 2]){
            dp[i / 2] = dp[i] + 1;
            path[i / 2] = i;
        }
        if(dp[i] + 1 < dp[i - 1]){
            dp[i - 1] = dp[i] + 1;
            path[i - 1] = i;
        }
    }
    cout << dp[1] << ln;
    int op = 10 , idx = 1;
    cout << 1 << ' ';
    while(1){
        cout << path[idx] << ' ';
        idx = path[idx];
        if(idx == n) break;
    }
}
 
int main() {
    io();
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
