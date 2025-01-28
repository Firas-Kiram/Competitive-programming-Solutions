#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c),end(c)
#define ssize(c) (int)c.size()
#define pb push_back
using ll = long long;
using ld = long double;
using vll = vector<ll>;

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
template<typename T>
void vdbg(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
const ll N = 1e6 + 100;

void solve() {
    ll n;cin >> n;
    vll A(n) , B(n) , a , b;
    for(int i = 0 ; i < n ; i ++) cin >> A[i];
    for(int i = 0 ; i < n ; i ++) cin >> B[i];
    vector <pair <ll , ll>> v(n);
    a = A , b = B;
    for(int i = 0 ; i < n ; i ++) v[i] = {B[i] , i};
    sort(all(v));
    for(int k = 0 ; k < n ; k ++ ){
        int i = v[k].second;
        if(a[i] == b[i]) continue;
        ll mx = a[i] , x = 2;
        ll l = i , r = i;
        for(int j = i ; j >= 0 ; j --){
            if(a[j] > b[i]) break;
            ckmax(mx , a[j]) , l = j;
            if(mx == b[i]) break;
        }
        bool ok = 1;
        for(int j = l ; j <= r ; j ++)
            ok &= (mx <= b[j]);
        if(ok){
            while(l <= r){
                a[l] = mx , l ++ ;
            }
        }
        l = i , r = i , mx = a[i];
        for(int j = i ; j < n ; j ++){
            if(a[j] > b[i]) break;
            ckmax(mx , a[j]) , r = j;
            if(mx == b[i]) break;
        }
        ok = 1;
        for(int j = l ; j <= r ; j ++){
            ok &= (mx <= b[j]);
        }
        if(ok){
            while(l <= r){
                a[l] = mx , l ++ ;
            }
        }
    }
    for(int i = 0 ; i < n ; i ++)
        if(a[i]!=b[i])return void(cout << "NO\n");
    cout << "YES\n";
}


signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int T = 1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
