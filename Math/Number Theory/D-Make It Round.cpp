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
    ll n , k;cin >> n >> k;
    ll res = 1 , ans = n;
    vector <int> a = {-1 , 10 , 5 , 10 , 5 , 2 , 5 , 10 , 5 , 10};
    ll p = k;
    while(n){
        ll y = 10 , nx = 1;
        while((n % y) / nx == 0){
            y*=10 , nx*=10;
        }
        p = k - res;
        res *= a[(n % y) / nx];
        if(res > k) {
            break;
        }
        ans*=a[(n % y) / nx];
        n = a[(n % y) / nx] * n;
    }
    auto get = [&](ll ans){
        ll j = 1 , x = 10 , nx = 0;
        while((ans % x) / j == 0){
            nx ++;
            x*=10 , j *= 10;
        }
        return nx;
    };
    ll nx = get(ans) , tot = ans;
    for(int i = 2 ; i <= p + 1; i ++){
        ll a = get(ans * i);
        if((k - p) * i > k) break;
        if(a >= nx){
            tot = ans*i;
        }
    }
    cout << tot << ln;
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
