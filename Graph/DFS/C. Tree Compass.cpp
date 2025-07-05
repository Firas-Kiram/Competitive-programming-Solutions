
/* 
  problem : C. Tree Compass - https://codeforces.com/contest/1943/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100;
vector <int> edj[N] , dist , vec ;
int nd , mx , target;

void dfs(int node , int anc) {
    if(dist[node] > mx) mx = dist[node] , nd = node;
    for(auto to : edj[node]) {
        if(to != anc)
            dist[to] = dist[node] + 1 , dfs(to , node);
    }
}

bool work(int node , int anc) {
    if(node == target) {
        vec.pb(node); return 1;
    }
    for(auto to : edj[node]) {
        if(to == anc) continue;
        if(work(to , node)) { 
            vec.pb(node);
            return 1;  
        }
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt --) {
        int n; cin >> n;
        mx = 0 , nd = 0;    
        vec.clear();
        dist = vector <int>(n + 5 , {});
        for(int i = 0 ; i <= n ; i ++) 
            edj[i].clear();
        for(int i = 0 ; i < n - 1 ; i ++ ) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v);
            edj[v].pb(u);
        }
        if(n == 1) {
            cout << "1\n1 0\n";
            continue;
        }
        dfs(1 , -1);
        for(int i = 0 ; i <= n ; i ++) 
            dist[i] = 0;
        target = nd , mx = 0 ;
        dfs(nd , -1);
        work(nd , -1);
        if((mx + 1) & 1) {
            cout << (mx + 1) / 2 + 1 << '\n';
            for(int i = 0 ; i <= (mx + 1) / 2 ; i ++) {
                cout << vec[ (int)vec.size() / 2 ] << ' ' << i << '\n';
            } 
        }else {
            int m = vec.size() / 2;
            vector <pair <int , int>> res;
            for(int i = 1 ; i <= ((mx + 1) / 2) ; i ++) {
                if(i % 2 == 0) continue;
                res.pb({vec[m - 1] , i}); res.pb({vec[m] , i});
            }
            cout << res.size() << '\n';
            for(auto [x , y] : res ) cout << x << ' ' << y << '\n';
        }     
    }
    return 0;
}
 
