/*
  problem : G1. Medium Demon Problem (easy version) - https://codeforces.com/problemset/problem/2044/G1
*/
#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
using ll = long long;
const ll N = 2e5 + 100 , LOG = 27;

vector <int> edj[N] , Adj[N] , anc , vec , vis;
vector <bool> cycle;

void dfs(int node) {
    vis[node] = 1;
    for(auto to : edj[node]){
        anc[to] = node;
        if(vis[to] == 0) {
            dfs(to);
        }else if(vis[to] == 1) {
            int x = anc[to]; vec.pb(to); cycle[to] = 1;
            while(x != to) {
                vec.pb(x);cycle[x] = 1; x = anc[x];
            }
        }
    }
    vis[node] = 2;
}

void dfs2(int node , int par , int cnt , int &res) {
    res = max(res , cnt + 2);
    for(auto to : Adj[node]) {
        if(cycle[to] || to == par) continue;
        dfs2(to , node , cnt + 1 , res);
    }
}

int main(){
    // freopen("parachute.in", "r", stdin);
	// freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    ll tt = 1;
    cin >> tt; 
    while(tt--){
        int n; cin >> n;
        vis = anc = vector <int>(n + 1 , {});
        cycle = vector <bool>(n + 1 , false);
        for(int i = 1 ; i <= n ; i ++) {
            int u ; cin >> u;
            edj[i].pb(u); Adj[i].pb(u); Adj[u].pb(i);
        }
        int res = 2;
        for(int i = 1 ; i <= n ; i ++) {
            if(!vis[i]) dfs(i);
        }
        for(auto to : vec)
            dfs2(to , -1 , 0 , res);
        cout << res << '\n';
        for(int i = 0 ; i <= n ; i ++) {
            edj[i].clear(); Adj[i].clear();
        } 
        vec.clear();
    }
    return 0;
}
