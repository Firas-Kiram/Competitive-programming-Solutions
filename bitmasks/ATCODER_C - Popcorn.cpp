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
ll x = 0;
vector <ll> v;
ll n , m;

ll work(ll i , ll s){
    if(i > n) return INT_MAX;
    if(s == x && i == n){
        return 0;
    }

    ll x = work(i + 1 , s);
    ll y = work(i + 1 , s | v[i]) + 1;
    return min(x , y);
}

void solve() {
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
        x |= (1 << i);
    }
    for(int i = 0 ; i < n ; i ++){
        string s;cin >> s;
        ll nx = 0;
        for(int j = 0 ; j < m ; j ++){
            if(s[j] == 'o'){
                nx |= (1 << j);
            }
        }
        v.pb(nx);
    }
    cout << work(0 , 0);
}

 
int main() {
    io();
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
