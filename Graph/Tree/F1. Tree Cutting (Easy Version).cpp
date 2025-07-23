/*
  problem : Tree Cutting (Easy Version) - https://codeforces.com/problemset/problem/1118/F1
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 100 , LOG = 21;
vector <int> edj[N] , R , B , dp , lvl , CR , CB;
int ans = 0 , b = 0 , r = 0;
void dfs(int node) {
    dp[node] = 0;
    CR[node] = R[node] , CB[node] = B[node];
    for(auto to : edj[node]) {
        if(lvl[to] == 0) {
            lvl[to] = lvl[node] + 1;
            dfs(to);
            dp[node] += dp[to];
            CB[node] += CB[to];
            CR[node] += CR[to];
        }else if(lvl[node] > lvl[to]) {
            dp[node] ++ ;
        }else if(lvl[node] < lvl[to]) {
            dp[node] -- ;
        }
    }
    dp[node] -- ;
    if(lvl[node] > 1 && dp[node] == 0) {
        if((CR[node] == r && CB[node] == 0) || CB[node] == b && CR[node] == 0) ans ++ ;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , st = -1; cin >> n;
        R = B = CR = CB = dp = lvl = vector <int>(n + 1 , {});
        for(int i = 1 ; i <= n ; i ++) {
            int x ; cin >> x;
            if(x == 1) R[i] ++ , r ++;
            else if(x == 2) B[i] ++ , st = i , b ++;
        }
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        lvl[st] = 1;
        dfs(st);
        cout << ans << '\n';
    }
}
