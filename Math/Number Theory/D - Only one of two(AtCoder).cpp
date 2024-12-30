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

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
const ll N = 2e5 + 100;

void solve() {
    ll n , m , k;
    cin >> n >> m >> k;
    ll l = 0 , r = 1e18 , L = lcm(n , m) , res = -1;
    while(r - l > 1){
        ll md = (l + r) / 2;
        ll M = md / m;
        ll N = md / n;
        ll nx = N + M - (md / L)*2;
        if(nx >= k){
            r = md;
            res = nx;
        }else l = md;
    }
    cout << r << '\n';
}



signed main() {
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    io();
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}      
