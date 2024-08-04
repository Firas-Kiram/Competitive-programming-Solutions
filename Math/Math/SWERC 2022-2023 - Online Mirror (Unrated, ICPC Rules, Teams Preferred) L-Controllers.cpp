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
void dbgv(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const ll N = 1e5 + 2000;
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; } 
void io() {ios::sync_with_stdio(false);cin.tie(NULL);}
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
vector <ll> v;

void solve() {
    ll n;cin >> n;
    string s;cin >> s;
    ll p = 0 , m = 0;
    for(int i = 0 ; i < n ; i ++){
        if(s[i] == '+') p ++;
        else m ++;
    }
    ll q;cin >> q;
    ll k = p - m;
    while(q --){
        ll a , b;cin >> a >> b;
        if(a < b)
            swap(a , b);
        if(k == 0) {
            yes
            continue;
        }
        if(k < 0){
            ll dif = a - b;
            ll x = dif * p;
            ll y = b * k; // -7 -7 
            y*=-1;
            if(x >= y && (y % dif)== 0){
                yes
            }else no
        }else {
            ll dif = a - b;
            ll x = dif * m;
            ll y = b * k; // -7 -7 
            if(x >= y && (y % dif)== 0){
                yes
            }else no
        }
    }
}

signed main() {
    io();
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
