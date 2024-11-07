#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll M = 1e6 + 100;

void solve() {
    ll n;cin >> n;
    vector <ll> a(n) , b(n) , pre(n , {});
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> b[i];
    pre[0] = a[0]*b[0];
    for(int i = 1 ; i < n ; i ++)
        pre[i] = (a[i] * b[i]) + pre[i - 1];
    ll res = pre.back();
    for(int i = 0 ; i < n ; i ++){
        ll tot = pre.back() , j = i - 1 , k = i + 1 , s = a[i]*b[i];
        while(j >= 0 && k < n){
            s += (a[j]*b[k] + a[k]*b[j]);
            tot = max(tot , pre.back() - (pre[k] - (j>0?pre[j-1]:0)) + s);
            j -- , k ++;
        }
        j = i , k = i + 1 , s = 0;
        while(j >= 0 && k < n){
            s += (a[j]*b[k] + a[k]*b[j]);
            tot = max(tot , pre.back() - (pre[k] - (j>0?pre[j-1]:0)) + s);
            j -- , k ++;
        }
        res = max(res , tot);
    }
    cout << res << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}   
