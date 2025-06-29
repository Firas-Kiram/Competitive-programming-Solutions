// problem : E - Find Permutation - https://atcoder.jp/contests/abc291/tasks/abc291_e
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin  >> tt; 
    while(tt--){
        int n , m , mx = 0; cin >> n >> m;
        vector <int> edj[n + 5] , deg(n + 1 , {}) , res;
        for(int i = 0 ; i < m ; i ++) {
            int u , v ; cin >> u >> v;
            deg[v] ++ , edj[u].pb(v);
        }
        queue <int> q;
        int cnt = 0;
        for(int i = 1 ; i <= n ; i ++)
            if(deg[i] == 0) q.push(i) , cnt ++;
        mx = max(cnt , mx);
        while(q.size()) {
            int node = q.front(); q.pop();
            res.pb(node); cnt = 0;
            for(auto to : edj[node]) {
                if(--deg[to] == 0)
                    q.push(to) , cnt ++;
                mx = max(mx , cnt);
            }
        }
        if((int)res.size() < n || mx > 1 ) cout << "No\n";
        else {
            cout << "Yes\n";
            vector <int> ans(n + 1 , {});
            for(int i = 0 ; i < n ; i ++) ans[res[i]] = i + 1;
            for(int i = 1 ; i <= n ; i ++) cout << ans[i] << ' ';cout << '\n';
        }
    }
    return 0;
}
