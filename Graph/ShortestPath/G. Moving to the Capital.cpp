
#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
using ll = long long;
const ll N = 1e6 + 100;



vector <int> edj[N] , dist , dp;

int work(int node) {
    if(dp[node] != (int)1e9) return dp[node];
    dp[node] = dist[node];
    for(auto to : edj[node]) {
        if(dist[node] < dist[to])
            dp[node] = min(dp[node] , work(to));
        dp[node] = min(dp[node] , dist[to]);
    }
    return dp[node];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 1;
    cin  >> tt; 
    while(tt--){
        int n , m; cin >> n >> m;
        dp = dist = vector <int>(m + 4 , (int)1e9);
        for(int i = 0 ; i < m ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v);
        }
        queue <int> q; q.push(1); dist[1] = 0;
        while(q.size()) {
            int node = q.front(); q.pop();
            for(auto it : edj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        for(int i = 1 ; i <= n ; i ++) cout << work(i) << ' ';cout << '\n';
        for(int i = 0 ; i <= n ; i ++) edj[i].clear();
    }
    return 0;
}
