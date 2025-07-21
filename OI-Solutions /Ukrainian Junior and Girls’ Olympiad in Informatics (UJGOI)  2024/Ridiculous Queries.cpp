#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

void solve() {  
    int n , q;
    cin >> n >> q;
    vector <int> v(n + 1);
    for(int i = 1 ; i <= n ; i ++)
        cin >> v[i];
    bool vis[n + 1];
    memset(vis , false , sizeof vis);
    vector <vector <ll>> A;
    for(int i = 1 ; i <= n ; i ++) {
        int x = v[i];
        vector <ll> a;
        while(!vis[x]) {
            vis[x] = 1; a.pb(x);
            x = v[x];
        }
        A.pb(a);
    }
    ll idx[n + 1] , grp[(int)A.size() + 1];
    for(int i = 0 ; i < A.size() ; i ++) {
        for(int j = 0 ; j < A[i].size() ; j ++) {
            int x = A[i][j];
            idx[x] = j , grp[x] = i;
        }
    }

    ll pre[n + 5][n + 5];
    for(int i = 0 ; i <= n ; i ++)
        for(int j = 0 ; j <= n ; j ++)
            pre[i][j] = 0;
    for(int i = 1 ; i <= n ; i ++) {
        for(int k = 1 ; k <= n ; k ++) {
            int x = v[i] ; int sz = A[grp[x]].size();
            pre[i][k] = A[grp[x]][(k - 1 + idx[x]) % A[grp[x]].size()] + i;
        }
    }
    vector <ll> res(n + 1 , {});
    for(int i = 1 ; i <= n ; i ++)  {
        ll mx = 0;
        for(int j = 1 ; j <= n ; j ++) {
            mx = max(mx , pre[j][i]);
        }
        res[i] = mx;
    }

    while(q -- ) {
        ll k ; cin >> k;
        ll idx = (k + (k % n)*(k/n)) % n;
        idx = (idx == 0 ? n : idx);
        cout << res[idx] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T; 
    while( T-- ) solve();
    return 0;
}
