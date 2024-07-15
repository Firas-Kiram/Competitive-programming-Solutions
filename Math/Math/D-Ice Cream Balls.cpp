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

bool work(ll x , ll n){
    return x * (x - 1)  >= (ll)n * 2;
}

void solve() {
    ll n;cin >> n;
    /*  n * (n - 1) / 2 = x
        x * 2 = n * (n - 1) -> x * 2 == n^2 - n
    */
    ll l = 0 , r = 2, ans = 0;
    while(!work(r - 1, n)) r <<= 1;
    while(r - l > 1){
        ll md = (l + r) >> 1;
        if(work(md , n)){
            r = md;
            ans = md;
        }else l = md;
    }
    ll k = ans*(ans - 1);
    if(k == n * 2) cout << ans << ln;
    else {
        ll p = ans - 1;
        p*=(ans-2);p >>=1;
        cout << ans - 1 + abs(p - n) << ln;
    }
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
