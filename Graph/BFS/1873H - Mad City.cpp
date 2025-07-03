/*
  problem : 1873H - Mad City - https://codeforces.com/contest/1873/problem/H
*/
#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
template <typename T>
void watch(const vector<T>& v) {
for (const auto& it : v) cout << it << ' ';cout<<'\n';}
const int N = 2e5 + 100;

vector <int> edj[N];
vector <bool> cycle;
vector <int> dist , anc , lvl ;

void dfs(int node , int par) {
    for(auto to : edj[node]) {
        if(lvl[to] == 0) {
            lvl[to] = lvl[node] + 1;
            anc[to] = node;
            dfs(to , node);
        }else if(lvl[node] > lvl[to] && to != par) {
            vector <int> vec;
            int x = node;
            while(x != to) {
                vec.pb(x);
                x = anc[x];
            }
            vec.pb(to);
            for(auto it : vec) cycle[it] = 1;
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    // precount();
    while(tt --) {
        int n , a , b ; cin >> n >> a >> b ;
        for(int i = 0 ; i < n ; i ++){
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        dist = anc = lvl = vector <int>(n + 5 , {});
        cycle = vector <bool> (n + 5 , false);
        lvl[1] = 1;
        dfs(1 , -1);

        function <vector <int> (int)> bfs = [&] (int node) {
            vector <int> vec(n + 1 , (int)1e8);
            queue <int> q;
            q.push(node);
            vec[node] = 0;
            while(q.size()) {
                int u = q.front(); q.pop();
                for(auto to : edj[u]) {
                    if(vec[to] > vec[u] + 1){
                        vec[to] = vec[u] + 1;
                        q.push(to);
                    }
                }
            }
            return vec;
        };

        vector <int> A = bfs(a);
        vector <int> B = bfs(b);
        bool ok = 0;
        for(int i = 1 ; i <= n ; i ++) {
            if(!cycle[i]) continue;
            ok |= (B[i] < A[i]);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        for(int i = 0 ; i <= n ; i ++) edj[i].clear();
    }   
    return 0;
}
 
