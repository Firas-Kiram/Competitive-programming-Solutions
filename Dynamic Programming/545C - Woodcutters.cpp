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
ll n,k,d;
vector <ll> v(M) , h(M);
ll dp[M];

ll work(ll i , ll nx){
    if(i >= n - 1) return 0;
    ll a = -1e9 , b = -1e9 , c = -1e9;
    ll&ret = dp[i];
    if(ret != -1) return ret;
    if(i - 1 >= 0) ckmax(nx , v[i - 1]);
    if(v[i] - h[i] > nx && v[i] - h[i] > v[i - 1]) {
        a = max(work(i + 1 , v[i]) + 1 , work(i + 1 , v[i]));
    }
    if(v[i] > nx && v[i] + h[i] < v[i + 1]) {
        b = work(i + 1 , v[i] + h[i]) + 1;
    }
    c = work(i + 1 , v[i]);
    return ret = max({a , b , c});
}


void solve() {
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> v[i] >> h[i];
    }
    if(n == 1) OUTRET(1);
    memset(dp , -1 , sizeof(dp));
    cout << work(1 , v[0]) + 2 << ln;
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
