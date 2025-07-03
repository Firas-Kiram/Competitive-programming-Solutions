/*
  problem : C. Tree Pruning - https://codeforces.com/contest/2018/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
template <typename T>
void watch(const vector<T>& v) {
for (const auto& it : v) cout << it << ' ';cout<<'\n';}
const int N = 2e6 + 100;

vector <int> edj[N] , dp , lvl;
void dfs(int node , int anc) {
    dp[node] = lvl[node];
    for(auto to : edj[node]) {
        if(to == anc) continue;
        lvl[to] = lvl[node] + 1;
        dfs(to , node);
        dp[node] = max({ dp[to] , dp[node] , lvl[to]});
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt --) {
        int n ; cin >> n;
        dp = lvl = vector <int>(n + 1 , {});
        for(int i = 0 ; i < n - 1 ; i ++){
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        dfs(1 , -1);
        vector <int> v;
        for(int i = 2 ; i <= n ; i ++) v.pb(dp[i]);
        sort(all(lvl));
        sort(all(v));
        set <int> st(all(v));
        int res = (int)1e9;
        for(auto to : st){
            int left = upper_bound(all(v) , to - 1) - v.begin();
            int right = upper_bound(all(lvl) , to) - lvl.begin();
            int tot = left + (int)lvl.size() - right;
            res = min(res , tot);
        }
        cout << res << '\n';
        for(int i = 0 ; i <= n ; i ++) edj[i].clear() ;
    }   
    return 0;
}
 
