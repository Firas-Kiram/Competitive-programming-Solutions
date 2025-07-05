/*
  problem : C - Underground Lab.cpp - https://codeforces.com/contest/781/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
template <typename T>
void watch(const vector<T>& v) {
for (const auto& it : v) cout << it << ' ';cout<<'\n';}
const int N = 2e6 + 100;
vector <vector <int>> res;
vector <int> edj[N] , setik;
vector <bool> vis;
int n , m , k , mx = 0 , cnt = 0;

void dfs(int node , int anc) {
    if((int)setik.size() == mx)
        res.pb(setik) , setik.clear();
    vis[node] = 1;
    for(auto to : edj[node]) {
        if(vis[to])  continue;
        setik.pb(to);
        dfs(to , node);
    }
    if(anc != -1)   setik.pb(anc);
    if((int)setik.size() == mx)
        res.pb(setik) , setik.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        cin >> n >> m >> k;
        vis = vector <bool>(n + 5 , false);
        mx = (2 * n + k - 1) / k;
        for(int i = 0 ; i < m ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        dfs(1 , -1);
        if(setik.size()) res.pb(setik);
        for(auto vec : res) {
            cout << vec.size() << ' ';
            for(auto to : vec) cout << to << ' ';
            cout << '\n'; 
        }
        if(res.size() < k){
            for(int i = res.size() ; i < k  ; i ++ ) cout << "1 1\n";
        }
    }   

    return 0;
}
 
