/*
  problem : F. Vlad and Unfinished Business - https://codeforces.com/contest/1675/problem/F
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 100 , LOG = 21;
vector <int> edj[N] , deg;
vector <bool> vis , used;
int dist = 0 , target;

void dfs(int node , int anc , int c) {
    if(node == target) dist = c;
    for(auto to : edj[node]) {
        if(to != anc) dfs(to , node , c + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n , m ; cin >> n >> m ;
        int x , y ; cin >> x >> y; target = y;
        used = vis = vector <bool>(n + 1 , false);
        deg = vector <int> (n + 1 , {});
        for(int i = 0 ; i < m ; i ++) {
            int c ; cin >> c ;
            vis[c] = 1;
        }
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v; deg[u] ++ , deg[v] ++ ;
            edj[u].pb(v); edj[v].pb(u);
        }
        queue <int> q;
        for(int i = 1 ; i <= n ; i ++) {
            if(deg[i] == 1 && !vis[i] && x != i && y != i) q.push(i);
        }
        int k = n;
        while(q.size()) {
            int u = q.front(); q.pop();
            used[u] = 1; k -- ;
            for(auto to : edj[u]) {
                if(--deg[to] == 1 && !vis[to] && to != x && to != y)
                    q.push(to);
            }
        }
        // for(int i = 1 ; i <= n ; i ++) cout << used[i] << ' ';cout << '\n';
        dfs(x , -1 , 0);
        cout << (k - 1) * 2 - dist << '\n';
        for(int i = 1 ; i <= n ; i ++) {
            used[i] = 0; edj[i].clear();
        }
    }
}
