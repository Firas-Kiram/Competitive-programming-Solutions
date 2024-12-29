#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
template<typename T>
void watch(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
void io(){ios::sync_with_stdio(false);cin.tie(NULL);}
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
const ll N = 3e5 + 100;
vector <ll> edj[N];
vector <bool> vis;
vector <ll> d;
void dfs(ll node){
    d[node] = vis[node] = 1;
    for(int v : edj[node]){
        if(vis[v]) continue;
        dfs(v);
        d[node] += d[v];
    }
}
void solve() {
    ll n , res = 1 ;cin >> n;
    d.assign(n + 1 , {});
    vis.assign(n + 1 , false);
    for(int i = 0 ; i < n - 1 ; i ++){
        ll u , v;cin >> u >> v;
        edj[u].pb(v);
        edj[v].pb(u);
    }
    dfs(1);
    vector <ll> a;
    for(auto it : edj[1]) a.pb(d[it]);
    sort(all(a));
    ll x = edj[1].size();
    for(int i = 0 ; i < min((int)x - 1 , (int)a.size()) ; i ++) 
        res += a[i];
    cout << res << '\n';
}



signed main() {
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    io();
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}      
