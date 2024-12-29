#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
template<typename T>
void watch(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
void io(){ios::sync_with_stdio(false);cin.tie(NULL);}
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void solve() {
    ll n , m , k;cin >> n >> m >> k;
    vector <ll> v(n) , pre(n , {}) , a(n , {}) , b(n + 1 , {});
    for(int i = 0 ; i < n ; i ++) cin >> v[i];
    pre[0] = v[0];ll s = v[0];
    if(s >= k) a[0] ++ , s = 0;
    for(int i = 1 ; i < n ; i ++){
        pre[i] = pre[i - 1] + v[i];
        s += v[i];
        if(s >= k) a[i] ++ , s = 0;
    }
    for(int i = 1 ; i < n ; i ++) a[i] += a[i - 1];
    s = v[n - 1];
    if(s >= k) b[n - 1] ++ , s = 0;
    for(int i = n - 2 ; i >= 0 ; i --){
        s += v[i];
        if(s >= k) b[i] ++ , s = 0;
    }
    for(int i = n - 2 ; i >= 0 ; i--) b[i] += b[i + 1];
    ll res = -1;
    for(int i = 0 ; i < n ; i ++){
        ll nx = (i ? a[i - 1] : 0);
        ll l = i - 1 , r = n + 1;
        while(r - l > 1){
            ll md = (l + r) >> 1;
            if(b[md] + nx >= m) l = md;
            else r = md;
        }
        if(l > 0){
            ckmax(res , pre[l - 1] - (i ? pre[i - 1] : 0));
        }
        if(l >= 0 && i <= l &&nx + b[l] >= m) ckmax(res , 0ll);

    }
    cout << res << '\n';
}


signed main() {
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    io();
    int T = 1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}      
