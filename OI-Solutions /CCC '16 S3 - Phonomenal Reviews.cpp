// problem : CCC '16 S3 - Phonomenal Reviews - https://dmoj.ca/problem/ccc16s3


#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 100;
vector <int> edj[N] , d;
vector <bool> removed , vis , c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , m ; cin >> n >> m;
        c = vis = removed = vector <bool> (n , false);
        d = vector <int> (n , {});
        for(int i = 0 , x ; i < m ; i ++) {
            cin >> x; c[x] = 1;
        }
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v; cin >> u >> v;
            edj[u].pb(v); edj[v].pb(u);
            d[u] ++ , d[v] ++ ;
        }   
        queue <int> q;
        for(int i = 0 ; i < n ; i ++){
            if(d[i] > 1 || c[i]) continue;
            q.push(i); removed[i] = 1;
        }
        
        while(q.size()) {
            int u = q.front();q.pop();
            for(auto to : edj[u]){
                if(removed[to]) continue;
                d[to] -- ;
                if(d[to] == 1 && !c[to]) {
                    q.push(to); removed[to] = 1;
                }
            }
        }
        int nd = 0 , mx = 0 , res = 0;

        function <void(int , int , int)> dfs = [&](int node , int anc , int cnt) -> void {
            if(removed[node] || vis[node]) return ;
            vis[node] = 1;
            if(cnt > mx) {
                mx = cnt; nd = node;
            }
            cnt ++ ;
            for(auto to : edj[node]) {
                if(vis[to] || removed[to]) continue;
                res ++ ;
                dfs(to , node , cnt);
                res ++ ;
            }
        };
        int st = 0;
        for(int i = 0 ; i < n ; i ++){
            if(!removed[i]){
                st = i; break;
            }

        }
        dfs(st , -1 , 0 );
        for(int i = 0 ; i < n ; i ++) vis[i] = 0;
        dfs(nd , -1 , 0 );
        res >>= 1;
        cout << res - mx << '\n';
    }

    return 0;
}
 
