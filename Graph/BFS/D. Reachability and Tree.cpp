/*
  problem : D. Reachability and Tree - https://codeforces.com/contest/2112/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt --) {
        int n ; cin >> n;
        vector <int> d(n + 1 , {}) , edj[n + 1];
        vector <pair <int , int>> vec(n - 1);
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v; vec[i] = {u , v};
            edj[u].pb(v); edj[v].pb(u);
            d[u] ++ , d[v] ++ ;
        }
        map <pair <int , int> , bool> used;
        vector <pair <int , int>> res;
        int col[n + 1];
        bool vis[n + 1] , ok = 0;
        for(int i = 0 ; i <= n ; i ++) vis[i] = 0 , col[i] = -1;
        queue <int> q;
        for(int i = 1 ; i <= n ; i ++) {
            if(d[i] == 2) {
                ok = 1;
                for(int j = 0 ; j < edj[i].size() ; j ++) {
                    auto &to = edj[i][j]; q.push(to); vis[to] = 1;
                    if(j & 1) res.pb({to , i}) , col[i] = 1 , col[to] = 0;
                    else res.pb({i , to}) , col[to] = 1;
                    used[{to , i}] = used[{i , to}] = 1;
                }
                break;
            }
        }
        while(q.size()) {
            int node = q.front(); q.pop();
            for(auto to : edj[node]) {
                if(col[to] != -1) continue;
                if(col[node] == 0) {
                    col[to] = 1;
                    res.pb({node , to});
                }else { 
                    col[to] = 0;
                    res.pb({to , node});
                }
                q.push(to);
            }
        }
        if(ok) {
            cout << "YES\n";
            for(auto [x , y] : res) cout << x << ' ' << y << '\n';
        }else cout << "NO\n";
    }   
    return 0;
}
 
