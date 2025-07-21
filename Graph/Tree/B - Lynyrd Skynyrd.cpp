/*
  problem : B. Lynyrd Skynyrd - https://codeforces.com/contest/1142/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 100 , LOG = 32;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , m , q; cin >> n >> m >> q ;
    vector <int> p(n) , a(m) , idx(n , {});
    for(int i = 0 ; i < n ; i ++) {
        cin >> p[i]; --p[i];
        idx[p[i]] = i;
    }
    for(int i = 0 ; i < m ; i ++) cin >> a[i] , a[i]--;
    vector <vector <int>> anc( m + 1 , vector <int>(LOG , m));
    vector <int> lst(n , m);
    for(int i = m - 1 ; i >= 0 ; i --) {
        int nxt = p[(idx[a[i]] + 1) % n];
        anc[i][0] = lst[nxt];
        lst[a[i]] = i;
    }
    for(int i = 1 ; i < LOG ; i ++) {
        for(int j = 0 ; j < m ; j ++) {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
    vector <int> res(m , m);
    for(int i = m - 1 ; i >= 0 ; i --) {
        ll k = 1 , node = i;
        for(ll j = LOG - 1 ; j >= 0 ; j --) {
            if(((n - 1ll) >> j) & 1) {
                node = anc[node][j];
            }
        }
        res[i] = node;
        if(i + 1 < m) res[i] = min(res[i] , res[i + 1]);
    }
    while(q -- ) {
        ll l , r ; cin >> l >> r; -- l , -- r;
        cout << (res[l] <= r);
    }
}
