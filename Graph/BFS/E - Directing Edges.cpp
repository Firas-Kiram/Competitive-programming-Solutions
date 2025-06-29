// problem : E - Directing Edges - https://codeforces.com/contest/1385/problem/E
#include <bits/stdc++.h>
using namespace std;
#define pb push_back


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1 , cs = 1;
    cin >> tt;
    while(tt --) {
        int n , m;
        cin >> n >> m;
        vector <int> edj[n + 5] , deg(n + 1 , {}) , x(m) , order(n + 1 , {}) , tp;
        vector <pair <int , int>> res(m);
        for(int i = 0 ; i < m ; i ++) {
            int u , v; cin >> x[i] >> u >> v; res[i] = {u , v};
            if(x[i] == 1) {
                edj[u].pb(v); deg[v] ++ ;
            }
        }
        queue <int> q;
        for(int i = 1 ; i <= n ; i ++) {
            if(deg[i] == 0)
                q.push(i);
        }
        int cnt = 1;
        while(q.size()) {
            int u = q.front(); q.pop();
            tp.pb(u);
            order[u] = cnt ++ ;
            for(auto to : edj[u]) {
                if(--deg[to] == 0) {
                    q.push(to);
                }
            }
        }
        if((int)tp.size() != n) {
            cout << "NO\n";
        }else {
            for(int i = 0 ; i < m ; i ++) {
                if(x[i]) continue;
                if(order[res[i].first] > order[res[i].second]) 
                    swap(res[i].first , res[i].second);
            }
            cout << "YES\n";
            for(auto [x , y] : res) cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}
 
