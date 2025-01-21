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

const ll N = 1e6 + 100;
const ll MOD = 998244353;

class DSU {
  private:
    vector<ll> parents ,sizes;
  public:
    DSU(ll size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }
    ll find(ll x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
    bool unite(ll x,ll y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
    bool same_(ll x,ll y) { return find(x) == find(y); }
};


void solve() {
    ll n , m;cin >> n >> m;
    vector <ll> v(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++) cin >> v[i];
    vector <pair <ll , pair <ll , ll>>> vec(m);
    for(int i = 0 ; i < m ; i ++){
        ll a , b , c;cin >> a >> b >> c;
        vec[i] = {c , {a , b}};
    }
    DSU d(n + 1);
    sort(all(vec) , greater <pair < ll , pair < ll , ll >>>());
    ll res = 1e11;
    for(auto [a , b] : vec) {
        if(v[b.F] == b.F && v[b.S] == b.S) continue;
        if(d.unite(b.F , b.S)) res = min(res , a);
    }
    cout << (res == 1e11 ? -1 : res) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
