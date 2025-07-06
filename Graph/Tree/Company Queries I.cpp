/*
  problem : Company Queries I - https://cses.fi/problemset/task/1687/
*/
#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100 , LOG = 23;

int anc[N][LOG];
vector<int> edj[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n , q;
        cin >> n >> q;
        for(int i = 2 ; i <= n ; i ++) cin >> anc[i][0];
        for(int i = 1 ; i < LOG ; i ++) {
            for(int j = 1 ; j <= n ; j ++) {
                anc[j][i] = anc[anc[j][i - 1]][i - 1];
            }
        }

        for(int i = 0 ; i < q ; i ++) {
            int x , k ; cin >> x >> k;
            for(int j = 0 ; j < LOG ; j ++) {
                if((k >> j) & 1) {
                    x = anc[x][j];
                }
            }
            cout << (x ? x : -1) << '\n';
        }
    }
    return 0;
}
 
