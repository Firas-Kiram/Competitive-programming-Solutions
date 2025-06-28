// problem : E. Bertown roads - https://codeforces.com/contest/118/problem/E
#include <bits/stdc++.h>
using namespace std;
#define pb push_back


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , m ; cin >> n >> m;
        vector <int> edj[n + 5];
        vector <int> dp(n + 5 , {}) , lvl(n + 5 , {});
        for(int i = 0 ; i < m ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        int cnt = 0;
        vector <pair <int , int>> vec;
        function <void (int , int)> dfs = [&] (int node , int anc) -> void {
            dp[node] = 0;
            for(auto to : edj[node]){
                if(lvl[to] == 0) {
                    vec.pb({node , to});
                    lvl[to] = lvl[node] + 1;
                    dfs(to , node);
                    dp[node] += dp[to];
                }else if(lvl[node] > lvl[to]) {
                    dp[node] ++ ;
                    if(to != anc)
                        vec.pb({node , to});
                }else if(lvl[node] < lvl[to]) {
                    dp[node] --;
                }
            }
            dp[node] -- ;
            if(dp[node] == 0 && lvl[node] > 1) cnt ++ ;
        };
        lvl[1] = 1;
        dfs(1 , -1);
        if(cnt > 0) {
            cout << "0\n";
        }else {
            // cout << vec.size() << '\n';
            for(auto [x , y] : vec) cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}
 
