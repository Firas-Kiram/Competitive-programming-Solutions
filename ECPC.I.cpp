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
const ll N = 1e5 + 2000;
 
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
    ll n;
    cin >> n;
    string s;cin >> s;
    vector <ll> v(n , 0);
    for(int i = 0 ; i < n ; i ++)
        cin >> v[i];
    vector <pi> a;
    for(int i = 0 ; i < n ; i ++){
        ll nx = v[i];
        bool cond = 1;
        ll mn = i + 30;
        ckmin(mn , n);
        for(int j = i + 1; j < mn && cond ; j ++){
            for(ll k = 0 ; k < 30 ; k ++){
                bool ok = v[j] & (1LL << k);
                bool ok2 = nx & (1LL << k);
                if(ok && ok == ok2){
                    a.pb({i , j - 1});
                    cond = 0;
                    break;
                }
            }
            if(cond) nx |= v[j];
            if(cond && j == mn - 1){
                a.pb({i , j});
            } 
        }
    }
    ll ans = 1;
    for(auto it : a){   
        for(int i = 30 ; i >= 1; i --){
            ll mn = it.S;
            for(int j = it.F ; j <= it.S - i ; j ++){
                string st = s.substr(j , i + 1);
                bool pal = 1;
                for(int k = 0 ; k < sz(st) && pal ; k ++){
                    if(st[k] != st[sz(st) - 1 - k])
                        pal = 0;
                }
                if(pal)
                    ckmax(ans , (ll) i + 1 );
            }
            if(ans > i) break;
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
