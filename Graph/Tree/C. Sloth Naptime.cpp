/*
  problem : C. Sloth Naptime - https://codeforces.com/gym/102694/problem/C

*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100 , LOG = 23;
vector <int> edj[N];
int anc[N][LOG] , lvl[N];

void build(int node , int par) {
    anc[node][0] = par;
    for(int i = 1 ; i < LOG ; i ++)
        anc[node][i] = anc[anc[node][i - 1]][i - 1];
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
        if(anc[u][i] != anc[v][i]) u = anc[u][i] , v = anc[v][i];
    }
    return anc[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n ; 
        cin >> n;
        for(int i = 0 ; i < n - 1 ;  i ++){
            int a , b ; cin >> a >> b;
            edj[a].pb(b); edj[b].pb(a);
        }
        build(1 , -1);
        int q; cin >> q;
        for(int i = 0 ; i < q ; i ++) {
            int a , b , c ; cin >> a >> b >> c;
            int dist = lvl[a] + lvl[b] - 2 * lvl[LCA(a , b)];
            if(dist <= c) {
                cout << b << '\n';
            }else {
                int lca = LCA(a , b);
                int diff = lvl[a] - lvl[lca];
                if(c > diff) {
                    c -= diff;
                    int diff2 = lvl[b] - lvl[lca];
                    cout << work(b , diff2 - c) << '\n';
                }else cout << work(a , c) << '\n';
            }
        }
    }
    return 0;
}
 
