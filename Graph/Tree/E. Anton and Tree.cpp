/*
  problem : E. Anton and Tree - https://codeforces.com/contest/734/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 100;
vector <int> c , grp , edj[N] , Adj[N];
vector <bool> vis;
int cmp = 1;

void dfs(int node , int anc) {
    if(vis[node]) return ;
    if(c[node] != c[anc]) return ;
    vis[node] = 1; grp[node] = cmp;
    for(auto to : edj[node]) {
        if(c[to] != c[node] && grp[to] != 0) {
             Adj[cmp].pb(grp[to]);
        }
        dfs(to , node);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1 , cs = 1;
    // cin >> tt;
    while(tt --) {
        int n; cin >> n ; c = grp = vector <int> (n + 5 , {});
        vis = vector <bool>(n + 4 , false);
        for(int i = 1 ; i <= n ; i ++) cin >> c[i];
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        for(int i = 1 ; i <= n ; i ++) {
            if(vis[i]) continue;
            dfs(i , i); cmp ++ ;
        }
        int mx = 0 , nd = 0 , res = 0;
        vector <int> dist(n + 1 , {});
        for(int i = 1 ; i < cmp ; i ++) {
            for(auto to : Adj[i]) Adj[to].pb(i); 
        }
        function <void (int , int)> work = [&](int node , int anc) {
            if(dist[node] > mx) mx = dist[node] , nd = node;
            for(auto to : Adj[node]) {
                if(to == anc) continue;
                dist[to] = dist[node] + 1; 
                work(to , node); 
            }
        };
        dist[1] = 0;
        work(1 , -1);
        dist[nd] = 0;
        work(nd , -1);
        cout << (mx + 1) / 2 << '\n';
    }   
    return 0;
}
 
