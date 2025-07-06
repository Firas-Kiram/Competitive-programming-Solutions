/*
  problem : Company Queries II - https://cses.fi/problemset/task/1688/
*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100 , LOG = 23;

int anc[N][LOG] , lvl[N];
vector<int> edj[N];


int LCA(int u , int v) {
    if(lvl[u] < lvl[v]) swap(u , v);
    int k = lvl[u] - lvl[v];
    for(int i = LOG - 1 ; i >= 0 ; i --) {
        if((k >> i) & 1) u = anc[u][i];
    }
    if(u == v) return u;
    for(int i = LOG - 1 ; i >= 0 ; i --) {
        if(anc[u][i] != anc[v][i]) {
            u = anc[u][i] , v = anc[v][i];
        }
    }
    return anc[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , q;
        cin >> n >> q;
        lvl[1] = 0;
        for(int i = 2 ; i <= n ; i ++) {
            cin >> anc[i][0];
            lvl[i] = lvl[anc[i][0]] + 1;
        }
        for(int i = 1 ; i < LOG ; i ++) {
            for(int j = 1 ; j <= n ; j ++) {
                anc[j][i] = anc[anc[j][i - 1]][i - 1];
            }
        }
        for(int i = 0 ; i < q ; i ++) {
            int u , v ; cin >> u >> v;
            cout << LCA(u , v) << '\n';
        }
    }
    return 0;
}
 
