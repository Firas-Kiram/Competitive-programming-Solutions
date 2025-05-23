#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;
vector <bool> vis;
vector < ll > vec;

void prepa() {
    ll n = 1000000;
    vis = vector <bool> (n + 1 , true);
    for(ll i = 2 ; i <= n ; i ++) {
        if(!vis[i]) continue;
        for(ll j = i + i ; j <= n ; j += i) vis[j] = false;
    } 
    for(int i = 2 ; i <= n ; i ++) if(vis[i]) vec.pb(i * 1ll * i); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    prepa();
    cin >> tt;
    while(tt--) {
        ll n , k ; cin >> n >> k;
        int x = upper_bound(all(vec), n) - vec.begin();
        int y = upper_bound(all(vec) , k) - vec.begin();
        if(n > k) cout << x << ' ' << x - y << '\n';
        else cout << x << " 0\n";
    }

    return 0;
}
