#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T --) {
        ll n , k , tot = 0; cin >> n >> k;
        vector <int> A[k] , a;
        int v[n + 1][2] , cnt[n + 1] = {} , idx[k];
        memset(v , -1 , sizeof v);
        for(int i = 0 ; i < k ; i ++) {
            ll x; cin >> x;
            A[i].resize(x); idx[i] = x - 1; tot += x;
            for(int j = 0 ; j < x ; j ++) {
                cin >> A[i][j]; ll nx = A[i][j];
                if(v[nx][0] == -1) v[nx][0] = i;
                else v[nx][1] = i;
            }
        }
        for(int i = 0 ; i < k ; i ++) {
            cnt[A[i].back()] ++ ;
            if(cnt[A[i].back()] % 2 == 0) a.pb(A[i].back());
        }
        tot /= 2;
        while(tot -- && a.size()){
            ll val = a.back(); a.pop_back();
            ll x = v[val][0] , y = v[val][1];
            idx[x] -- , idx[y] -- ;
            if(idx[x] >= 0) {
                ll nx = A[x][idx[x]]; cnt[nx] ++ ;
                if(cnt[nx] % 2 == 0) a.pb(nx);
            }
            if(idx[y] >= 0) {
                ll nx = A[y][idx[y]]; cnt[nx] ++ ;
                if(cnt[nx] % 2 == 0) a.pb(nx);
            }
        }
        bool ok = 1;
        for(int i = 0 ; i < k ; i ++)
            if(idx[i] != -1) ok = 0;
        if(ok) cout << "Yes\n";
        else cout << "No\n"; 
    }
    return 0;
}
