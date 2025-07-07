/*
  problem : E. Tree Queries - https://codeforces.com/contest/1328/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e5 + 100 , LOG = 23;
int anc[N][LOG] , lvl[N];
vector <int> edj[N];

void build(int node , int par) {
    anc[node][0] = par;
    for(int i = 1 ; i < LOG ; i ++) {
        anc[node][i] = anc[anc[node][i - 1]][i - 1];
    }
    for(auto to : edj[node]) {
        if(to != par) lvl[to] = lvl[node] + 1 , build(to , node);
    }
}

int work(int node , int k) {
    for(int i = LOG - 1 ; i >= 0 ; i --) {
        if((k >> i) & 1) {
            node = anc[node][i];
        }
    }
    return node;
}

int LCA(int u , int v) {
    if(lvl[u] < lvl[v]) swap(u , v);
    u = work(u , lvl[u] - lvl[v]);
    if(u == v) return v;
    for(int i = LOG - 1 ; i >= 0 ; i --) {
        if(anc[u][i] != anc[v][i]) 
            u = anc[u][i] , v = anc[v][i];
    }
    return anc[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , k ; 
        cin >> n >> k;
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        build(1 , 1);
        for(int q = 0 ; q < k ; q ++) {
            int c ; cin >> c;
            bool ok = 1;
            vector <int> vec(c);
            for(int i = 0 ; i < c ; i ++) cin >> vec[i];
            int mn = (int)1e9 , nd = -1 , mx = -1 , nd2 = 0;
            for(auto to : vec) {
                if(lvl[to] > mx) mx = lvl[to] , nd2 = to;
            }
            for(int i = 0 ; i < vec.size() && ok ; i ++) {
                int lca = LCA(nd2 , vec[i]);
                if(abs(lvl[lca] - lvl[vec[i]]) > 1) ok = 0;
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
 
