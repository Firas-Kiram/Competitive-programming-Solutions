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
vector <ll> adj[MAX];
vector <bool> vis;
vector <ll> col;
bool ok = 1;
void dfs(ll node , ll C){
    vis[node] = 1;
    col[node] = C;
    for(ll x : adj[node]){
        if(!vis[x]){
            dfs(x , C ^ 1);
        }else if(vis[x] && col[x] == C){
            ok = 0;
        }
    }
}

void solve() {  
    ll n , m;
    cin  >> n >> m ;
    vis.assign(n + 1 , 0);
    col.assign(n + 1 , -1);
    vector <pi> a;
    for(int i = 0 ; i < m ; i ++){
        ll u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        a.pb({u , v});
    }
    dfs(1 , 0);
    if(!ok)
        OUTRET("NO");
    yes
    for(int i = 0 ; i < m ; i ++){
        if(col[a[i].F] == 1)
            cout << 1;
        else cout << 0;
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
