// problem : F - Chat Screenshots - https://codeforces.com/contest/1931/problem/F
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin  >> tt; 
    while(tt--){
        int n , k ; cin >> n >> k;
        vector <int> edj[n + 1] , deg(n + 1 , {});
        for(int i = 0 ; i < k ; i ++) {
            int lst = 0;
            for(int j = 0 , x ; j < n ; j ++) {
                cin >> x; 
                if(j <= 1)  {
                    lst = x; continue;
                }
                edj[lst].pb(x); deg[x] ++; lst = x;
            }
        }
        queue <int> q;
        for(int i = 1 ; i <= n ; i ++) {
            if(deg[i] == 0) q.push(i);
        }
        vector <int> res;
        while(q.size()) {
            int node = q.front(); q.pop(); res.pb(node);
            for(auto to : edj[node]){
                if(--deg[to] == 0)
                    q.push(to);
            }
        }
        if((int)res.size() != n) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
