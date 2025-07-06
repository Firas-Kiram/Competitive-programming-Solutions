/*
  problem : Planets Queries I - https://cses.fi/problemset/task/1750/
*/
#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100 , LOG = 31;
int anc[N][LOG];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , q ; cin >> n >> q;
        for(int i = 1 ; i <= n ; i ++) {
            int u ; cin >> u;
            anc[i][0] = u;
        }
        
        for(int i = 1 ; i < LOG ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                anc[j][i] = anc[anc[j][i - 1]][i - 1];
        
        while(q --) {
            int u , k; cin >> u >> k;
            for(int i = LOG - 1 ; i >= 0 ; i --)
                if((k >> i) & 1) u = anc[u][i];
            cout << u << '\n';
        }
    }
    return 0;
}
 
