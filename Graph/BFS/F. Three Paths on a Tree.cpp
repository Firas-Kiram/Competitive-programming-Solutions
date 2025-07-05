
/*
  problem : F. Three Paths on a Tree - https://codeforces.com/contest/1294/problem/F
*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n;cin >> n;
        vector <int> edj[n + 50];
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
        }
        vector <int> anc(n + 10 , -1) , dist , a;
        function <pair <int , int> (int)> bfs = [&](int st) -> pair <int , int> {
            dist = vector <int> (n + 10 , (int)1e9);
            queue <int> q;
            q.push(st); dist[st] = 0;
            int mx = 0 , nd = 0 , cnt = 10;
            while(q.size()) {
                int node = q.front(); q.pop();
                if(dist[node] > mx) mx = dist[node] , nd = node;
                for(auto to : edj[node]) {
                    if(dist[node] + 1 < dist[to]) {
                        q.push(to); dist[to] = dist[node] + 1;
                        anc[to] = node;
                    }
                }
            }
            return make_pair(nd , mx);
        };
        int u = bfs(1).first;
        auto [v , d] = bfs(u) ; int x = v;
        while( x != u ) a.pb(x) , x = anc[x];
        a.pb(x);
        bool used[n + 1];
        memset(used , false , sizeof used);
        for(auto to : a) used[to] = 1;
        int mx = 0 , nd = 0; dist = vector <int>(n + 1 , (int)1e9);
        for(int i = 0 ; i < a.size() ; i ++) {
            int node = a[i];
            if(nd == 0 && a[i] != u  && a[i] != v) nd = a[i];
            queue <int> q;
            q.push(a[i]); dist[a[i]] = 0;
            while(q.size()) {
                int node = q.front(); q.pop();
                if(dist[node] > mx){
                    mx = dist[node] , nd = node;
                }
                for(auto to : edj[node]) {
                    if(used[to]) continue;
                    if(dist[to] > dist[node] + 1) {
                        q.push(to); dist[to] = dist[node] + 1;
                    }
                }
            }
        }
        cout << d + mx << '\n';
        cout << u << ' ' << v << ' ' << nd << '\n';
    }   

    return 0;
}
 
