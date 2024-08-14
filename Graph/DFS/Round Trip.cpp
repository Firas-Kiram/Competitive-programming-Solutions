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
// const ll INF = 0x3f3f3f3fm3f3f3f3fLL;
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
vector <bool> vis(N);
vector <ll> adj[N];
vector <ll> p(N , 0);
vector <ll> tps;
bool ok = 0;

void dfs(ll node , ll par){
    vis[node] = 1;
    p[node] = par;
    for(ll x : adj[node]){
        if(x == par) continue;
        if(vis[x]){
            vector <ll> a;
            p[x] = node;
            ll nx = x;a.pb(x);
            while(p[nx] != x){
                nx = p[nx];
                a.pb(nx);
            }
            a.pb(x);
            cout << sz(a) << ln;
            for(ll it : a)
                cout << it << ' ';
            exit(0);
        }else dfs(x , node);
    }
}


void solve() {
    ll n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
        ll u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }    
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i]){
            tps.clear();
            dfs(i , -1);
        }
    }
    cout << "IMPOSSIBLE";
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
