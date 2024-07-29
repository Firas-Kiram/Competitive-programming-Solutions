#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define dbg(x) cout <<#x<<": "<<x<< ln;
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
const ll INF = 1000000000;
const ll MOD = 1e9 + 7;
const ll M = 1e6 + 8432;
const ll N = 2e5 + 2000;
 
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
 
void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll n;cin >> n;
    vector <ll> v(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> v[i];
    if(n == 1) return void(cout << 0 << ln);
    ll m = log2(n);
    vector <ll> a;
    for(int i = m ; i >= 0 ; i --){
        a.pb(1LL << i);
    }
    for(int i = 0 ; i < sz(a) ; i ++){
        for(int j = 0 ; j < n ; j += a[i]){
            ll mn = INT_MAX , mx = INT_MIN;
            for(int k = j ; k < j + a[i] ; k ++){
                ckmax(mx , v[k]);
                ckmin(mn , v[k]);
            }
            if(mx-mn!=a[i]-1)
                return void(cout << -1 << ln);
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < sz(a) - 1; i ++){
        for(int j = 0 ; j < n ; j += a[i]){
            ll mx = INT_MIN , mx2 = INT_MIN;;
            for(int k = j ; k < j + (a[i]) / 2 ; k ++){
                ckmax(mx , v[k]);
            }
            for(int k = j + (a[i]) / 2 ; k < j + (a[i]) ; k ++){
                ckmax(mx2 , v[k]);
            }
            if(mx2 < mx){
                ans ++;
            }
        }
    }
    cout << ans << ln;

}
    

 
int main() {
    io();
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}



/*  
    BEFORE coding are you sure you understood the statement correctly?
    PLEASE do not forget to read the sample explanation carefully.
    WATCH out for overflows & RTs in general.
    TEST your idea or code on the corner cases.
    ANALYZE each idea you have thoroughly.
    - try greedy, sorting, dp, binary_search, math B,C.
    - problems involving minimmizing a maximum often ( binary search )
*/
