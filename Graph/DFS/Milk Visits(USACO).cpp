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
const ll N = 1e6 + 500;
vector <bool> vis(N);
vector <ll> edj[N];
vector <ll> comp(N);
string s;
ll grp = 0;
void dfs(ll u , char c){
    vis[u] = 1;
    comp[u] = grp;
    for(ll x : edj[u]){
        if(!vis[x] && c == s[x - 1])
            dfs(x , c);
    }
}

void solve() {  
    ll n , m;
    cin >> n >> m;
    cin >> s;
    for(int i = 0 ; i < n - 1 ; i ++){
        ll u , v;
        cin >> u >> v;
        edj[u].pb(v);
        edj[v].pb(u);
    }
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i])
            dfs(i , s[i - 1]);
        grp ++ ;
    }
    for(int i = 0 ; i < m ; i ++){
        ll u , v ;
        char c;
        cin >> u >> v >> c;
        if(comp[u]!=comp[v]){
            cout << 1;
            continue;
        }
        if(c == 'H'){
            if(s[u - 1] == 'H') cout << 1 ;
            else cout << 0;
        }else if(c == 'G'){
            if(s[u - 1] == 'G') cout << 1;
            else cout << 0;
        }
    }
}

int main() {
    io();
    // #ifndef ONLINE_JUDGE
        freopen("milkvisits.in", "r", stdin);
        freopen("milkvisits.out", "w", stdout);
    // #endif // ONLINE_JUDGE
    int T = 1; 
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
