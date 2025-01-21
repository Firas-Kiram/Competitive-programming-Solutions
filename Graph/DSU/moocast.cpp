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
        x = find(x);
        y = find(y);
        if (x == y) { return false; }
        if (sizes[x] < sizes[y]) { swap(x, y); }
        sizes[x] += sizes[y];
        parents[y] = x;
        return true;
    }
    bool same_(ll x,ll y) { return find(x) == find(y); }
};

struct Edge{
    ll a , b , dist;
};
    
void solve() {
    ll n;cin >> n;
    vector <ll> a(n) , b(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i] >> b[i];
    }
    vector <Edge> v;
    for(int i = 0 ; i < n ; i ++){
        for(int j = i + 1 ; j < n ; j ++){
            ll dx = a[i] - a[j];
            ll dy = b[i] - b[j];
            v.pb({i , j , dx * dx + dy * dy});
        }
    }
    auto cmp = [](const Edge &a ,const Edge &b){return a.dist < b.dist;};
    sort(all(v) , cmp);
    DSU d(n + 1);
    ll c = n , res = 0;
    for(Edge &e : v){
        if(d.unite(e.a , e.b)){
            c -- ;
            res = e.dist;
            if(c == 1) break;
        }
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
