#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;
const ll MOD = 1e9 + 7;

const ll N = 1e5 + 100;
ll n , m ;
vector < ll > v;

int main() {
    cin >> n >> m;
    v = vector < ll > (n);
    for(int i = 0 ; i < n ; i ++) cin >> v[i];
    ll dp[n][m + 1] = {};
    if(v[0] == 0) {
        for(int i = 1 ; i <= m ; i ++) dp[0][i] = 1;
    }else dp[0][v[0]] = 1;
    for(int i = 1 ; i < n ; i ++) {
        if(v[i] == 0) {
            for(int j = 1 ; j <= m ; j ++) {
                if(j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if(j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }else {
            if(v[i] - 1 >= 1) dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] - 1]) % MOD;
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i]]) % MOD;
            if(v[i] + 1 <= m) dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] + 1]) % MOD;
        }
    }
    ll res = 0;
    for(int i = 0 ; i <= m ; i ++) res = (res + dp[n - 1][i]) % MOD; 
    cout << res << '\n';
    return 0;
}
