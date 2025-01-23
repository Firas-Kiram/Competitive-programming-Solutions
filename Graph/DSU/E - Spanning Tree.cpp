#include<bits/stdc++.h>

using namespace std;
#define pb push_back
using ll = long long;
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
template<typename T>
void watch(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
#define all(x) (x).begin(), (x).end()

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

const ll N = 1e6 + 100;
ll dsu[N] , sz[N];

ll Find(ll u){
    return (dsu[u] == u ? u : dsu[u] = Find(dsu[u]));
}

bool Union(ll a ,ll b){
    a = Find(a) , b = Find(b);
    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a , b);
    sz[a] += sz[b];
    dsu[b] = a;
    return 1;
}

void solve() {
    ll n , m ;cin >> n >> m;
    vector <ll> mn(n + 1 , 1e14);
    for(int i = 0 ; i <= n ; i ++) {
        dsu[i] = i , sz[i] = 1;
    }
    vector <array <ll , 3>> a;
    for(int i = 0 ; i < m ; i ++){
        ll u , v ,cost;cin >> u >> v >> cost;
        a.pb({cost , u , v});
    }
    sort(all(a) , [&](array <ll , 3> x, array <ll , 3> y){
        return x[0] < y[0];
    });
    ll res = 0;
    for(auto it : a){
        ll u = it[1] , v = it[2];
        if(Union(u , v)) 
            res += it[0];
    }
    cout << res << '\n';
    // watch(mn);
}


signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
