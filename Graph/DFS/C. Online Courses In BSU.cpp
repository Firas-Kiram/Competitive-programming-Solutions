#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define ln '\n'
#define dbg(x) cout <<#x<<": "<<x<< ln;
void dbgv(vector<ll> v){for (auto x : v)cout<<x<<" ";cout <<ln;}
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; } 
void io() {ios::sync_with_stdio(false);cin.tie(NULL);}
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
const ll N = 1e5 + 500;
vector <ll> edj[N];
vector <bool> vis(N) , anc(N);
vector <ll> c;
bool cond = 0;
vector <ll> tps;
void dfs(ll u){
    vis[u] = anc[u] = 1;
    for(ll x : edj[u]){
        if(!vis[x])
            dfs(x);
        else if(anc[x] == 1)
            cond = 1;
    }
    anc[u] = 0;
    tps.pb(u);
}

void solve() {
    ll n , k;
    cin >> n >> k;
    c.assign(k , 0);
    for(int i = 0 ; i < k ; i ++){
        cin >> c[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        ll t;cin >> t;
        for(int j = 0 ; j < t ; j ++){
            ll u;cin >> u;  
            edj[i].pb(u);
        }
    }
    for(int i = 0 ; i < k ; i ++){
        if(!vis[c[i]])
            dfs(c[i]);
    }
    if(cond) 
        return void(cout << -1 << ln);
    cout << tps.size() << ln;
    for(ll x : tps)
        cout << x << ' ';
    cout << ln;

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
