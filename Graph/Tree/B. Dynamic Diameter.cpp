/*
  problem : B. Dynamic Diameter - https://codeforces.com/gym/102694/problem/B
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1 , cs = 1;
    // cin >> tt;
    while(tt --) {
        int n ; cin >> n;
        vector <int> dist(n + 1 , {}) , dp(n + 1 , {}) , edj[n + 1];
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        int mx = 0 , nd =0 ;
        function <void (int , int , int)    > dfs = [&] (int node , int anc , int st) -> void {
            if(dist[node] > mx) {
                mx = dist[node];nd = node;
            }    
            dp[node] = max(dp[node] , abs(dist[node] - dist[st]));
            for(auto to : edj[node]) {
                if(to == anc) continue;
                dist[to] = dist[node] + 1;
                dfs(to , node , st);
            }
        };
        dist[1] = 0;
        dfs(1 , -1 , 1);
        dist[nd] = 0;
        dfs(nd , -1 , nd);
        dist[nd] = 0;
        dfs(nd , -1 , nd);
        for(int i = 1 ; i <= n ; i ++) {
            cout << max(mx , dp[i] + 1) << '\n';
        }
    }   
    return 0;
}
 
