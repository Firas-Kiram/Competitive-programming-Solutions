/* 
  problem : F. Timofey and Black-White Tree - https://codeforces.com/contest/1790/problem/F
*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100;
vector <int> edj[N] , v , dist;
int res =  1e9 , ans = 1e9;

void dfs(int node ,int anc) {
    if(dist[node] > ans) return;
    for(auto to : edj[node]) {
        if(to == anc) continue;
        if(dist[node] + 1 < dist[to]) 
            dist[to] = dist[node] + 1 , dfs(to , node);
        else res = min(res , dist[node] + 1 + dist[to]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt --) {
        int n , c; cin >> n >> c;
        ans = res = 1e9;
        for(int i = 0 ; i <= n ; i ++) edj[i].clear();
        v = vector <int>(n - 1 , {});
        dist.assign(n + 1 , 1e8);
        for(int i = 0 ; i < n - 1 ; i ++) cin >> v[i];
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        dist[c] = 0;
        dfs(c , -1);
        for(int i = 0 ; i < n - 1 ; i ++) {
            res = 1e9; dist[v[i]] = 0;
            dfs(v[i] , -1); ans = min(ans , res);
            cout << ans << ' ';
        }
        cout << '\n';
    }   
    return 0;
}
 
