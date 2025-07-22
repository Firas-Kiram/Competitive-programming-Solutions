/*
  problem : D. A Wide, Wide Graph - https://codeforces.com/problemset/problem/1805/D
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 100 , LOG = 21;
 
vector <int> edj[N] , dp ;
int nd = 0 , mx = 0;
bool vis[N];

void dfs(int node , int anc , int c) {
    if(c > mx) mx = c , nd = node;
    dp[node] = max(dp[node] , c); 
    for(auto to : edj[node]) {
        if(anc != to) dfs(to , node , c + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    dp = vector <int>(n + 1 , {});
    for(int i = 0 ; i < n - 1  ; i ++) {
        int u , v ;cin >> u >> v;
        edj[u].pb(v); edj[v].pb(u);
    }
    dfs(1 , -1 , 0);
    mx = 0;
    dfs(nd , -1 , 0);
    mx = 0;
    dfs(nd , -1 , 0);
    mx ++ ;
    vector <int> vec; 
    for(int i = 1 ; i <= n ; i ++) vec.pb(dp[i]);
    sort(all(vec));
    for(int k = 1 ; k <= n ; k ++) {
        int idx = upper_bound(all(vec) , k - 1) - vec.begin();
        cout << min(n , idx + 1) << ' ';
    }

}
