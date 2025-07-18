/*
  problem : Distance Queries - https://cses.fi/problemset/task/1135/
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()
const int N = 2e5 + 100 , LOG = 31;
vector <int> edj[N] , lvl;
int anc[N][LOG];

void dfs(int Node , int par){
    anc[Node][0] = par;
    for(int i = 1 ; i < LOG ; i ++)
        anc[Node][i] = anc[anc[Node][i - 1]][i - 1];
    for(auto to : edj[Node]) if(to != par) 
        lvl[to] = lvl[Node] + 1 , dfs(to , Node);
}

int get(int Node , int k) {
    for(int i = 0 ; i < LOG ; i ++) {
        if((k >> i) & 1) Node = anc[Node][i];
    }
    return Node;
}

int LCA(int u , int v) {
    if(lvl[u] < lvl[v]) swap(u , v);
    u = get(u , lvl[u] - lvl[v]);
    if(u == v) return v;
    for(int i = LOG - 1 ; i >= 0 ; i -- ) {
        if(anc[u][i] != anc[v][i]) u = anc[u][i] , v = anc[v][i];
    }
    return anc[u][0];
}

int dist(int u , int v) {
    return (lvl[u] + lvl[v] - lvl[LCA(u , v)] * 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , m ; cin >> n >> m;
        lvl = vector <int> (n + 1 , {});
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        dfs(1 , 1);
        while(m --) {
            int u , v ; cin >> u >> v;
            cout << dist(u , v) << '\n';
        }
    }   
 
    return 0;
}
