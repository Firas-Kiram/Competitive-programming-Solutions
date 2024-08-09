#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define ln '\n'
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define dbg(x) cout <<#x<<": "<<x<< ln;
void dbgv(vector<ll> v){for (auto x : v)cout<<x<<" ";cout <<ln;}
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const ll N = 1e5 + 2000;
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; } 
void io() {ios::sync_with_stdio(false);cin.tie(NULL);}
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
map <ll , pi> cord;
vector <bool> vis;
vector <ll> adj[N];
void dfs(ll node , pi &X , pi &Y){
    vis[node] = 1;
    X = {max(cord[node].F , X.F) , min(cord[node].F , X.S)};
    Y = {max(cord[node].S , Y.F) , min(cord[node].S , Y.S)};
    for(ll x : adj[node]){
        if(!vis[x])
            dfs(x , X , Y);
    }
}
void solve() {
    ll n , m;
    cin >> n >> m;
    vis.assign(n + 5 , 0);
    for(int i = 0 ; i < n ; i ++){
        ll x , y;
        cin >> x >> y;
        cord[i + 1] = {x , y};
    }
    while(m --){
        ll a , b;cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll mn = INF;
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i]){
            pi X = {-1 , INF} , Y = {-1 , INF};
            dfs(i , X , Y);
            ll a = abs(X.S - X.F) * 1LL * 2LL;
            ll b = 2LL * 1LL * abs(Y.S - Y.F);
            ckmin(mn , a + b);
        }
    }
    cout << mn << ln;
}

signed main() { 
    io();
    // #ifndef ONLINE_JUDGE
        freopen("fenceplan.in", "r", stdin);
        freopen("fenceplan.out", "w", stdout);
    // #endif // ONLINE_JUDGE
    int T = 1; 
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
