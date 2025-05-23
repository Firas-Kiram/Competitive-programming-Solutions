#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;
const ll N = 1e6 + 105;
vector <int> spf;
ll pre[N][15];

int get(int x){
    set <int> ret;
    while(x > 1) {  
        ret.insert(spf[x]); x /= spf[x];
    }
    return (int)ret.size();
}

void prepa() {
    ll n = 1e6 + 100;
    spf = vector <int> (n + 1); iota(all(spf) , 0);
    for(int i = 2 ; i <= n ; i ++) {
        if(spf[i] != i) continue;
        for(int j = i ; j <= n ; j += i) if(spf[j] == j) spf[j] = i;
    }
    pre[1][0] ++ ;
    for(int i = 2 ; i <= n ; i ++) {
        int x = get(i);
        if(x <= 10)
            pre[i][x] ++ ;
    }
    for(int i = 1 ; i <= n ; i ++) {
        for(int j = 0 ; j <= 10 ; j ++) {
            pre[i][j] += pre[i - 1][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    prepa();
    cin >> tt;
    while(tt--) {
        int a , b , n; cin >> a >> b >> n;
        cout << pre[b][n] - pre[a - 1][n] << '\n'; 
    }

    return 0;
}
