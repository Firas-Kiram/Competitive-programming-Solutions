#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;

const int MOD = 1e9 + 7;
const ll N = 2e5 + 100;
vector <int> edj[N] , distroot(N) , distx(N);
int node , mx , res ;

void dfs(int u , int anc , int cnt , bool ok ) {
    if(ok) distroot[u] = cnt;
    else distx[u] = cnt;
    for(auto to : edj[u]) {
        if(to != anc) dfs(to , u , cnt + 1 , ok);
    }
}


int main() {
    // freopen("shop.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;

    while(tt--) {
        int n , x ; cin >> n >> x;
        for(int i = 0 ; i < n - 1 ; i ++) {
            int u , v ; cin >> u >> v;
            edj[u].pb(v) , edj[v].pb(u);
        }
        dfs(1 , -1 , 0 , 1);
        dfs(x , -1 , 0 , 0);
        node = x;
        for(int i = 1 ; i <= n ; i ++) {
            if(distroot[i] <= distx[i]) continue;
            res = max(res , distroot[i] * 2);
        }
        cout << res << '\n';
    }   

    return 0;
}
