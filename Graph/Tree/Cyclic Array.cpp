/*
  problem : Cyclic Array - https://cses.fi/problemset/task/1191/
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
    ll n , k ; cin >> n >> k; 
    vector <ll> v(2 * (n + 1)) , pre(2 * (n + 1) , {}) , nex(2 *(n + 1) , {});
    iota(all(nex), 0);
    ll anc[2 * (n + 1)][LOG];
    for(int i = 1 ; i <= n ; i ++) {
        cin >> v[i]; v[i + n] = v[i];
    }
    pre[1] = v[1];
    for(int i = 1 ; i <= n * 2 ; i ++) pre[i] = pre[i - 1] + v[i];
    for(int i = 1 , j = 1; i <= n * 2 ; i ++) {
        while( j <= 2 * n && pre[j] - pre[i - 1] <= k) j ++ ;
        anc[i][0] = j;
    }
    for(int i = 1 ; i < LOG ; i ++) {
        for(int j = 1 ; j <= n * 2 ; j ++) {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
    int mn = (int)1e8;
    for(int i = 1 ; i <= n ; i ++) {
        int idx = i , res = 0;
        for(int j = LOG - 1 ; j >= 0 ; j --) {
            if(anc[idx][j] < i + n) {
                idx = anc[idx][j]; res += (1 << j);
            }
        }
        mn = min(res + 1 , mn);
    }
    cout << mn << '\n';
}
