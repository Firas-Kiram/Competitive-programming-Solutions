/*
  problem : Subtree Queries - https://cses.fi/problemset/task/1137/
*/#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
template <typename T>
void watch(const vector<T>& v) {
for (const auto& it : v) cout << it << ' ';cout<<'\n';}
const int N = 2e6 + 100;

vector <long long> edj[N] , tin(N , {}) , tout(N , {});
int timer = 0;
template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return (a + b); }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) { // sum on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

void dfs(int node , int anc) {
    tin[node] = timer ++ ;
    for(auto to : edj[node]) {
        if(to != anc) dfs(to , node);
    }
    tout[node] = timer - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , q; cin >> n >> q;
        vector <int> v(n + 1 , {});
        for(int i = 1 ; i <= n ; i ++) cin >> v[i];
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        dfs(1 , -1);
        Seg <long long> sg;
        sg.init(n + 5);
        for(int i = 1 ; i <= n ; i ++)
            sg.upd(tin[i] , v[i]);
        while(q --) {
            int u; cin >> u;
            if(u == 1) {
                int s , x; cin >> s >> x;
                sg.upd(tin[s] , x);
                v[s] = x;
            }else {
                int s; cin >> s;
                cout << sg.query(tin[s] , tout[s]) << '\n';
            }
        }
    }

    return 0;
}
 
