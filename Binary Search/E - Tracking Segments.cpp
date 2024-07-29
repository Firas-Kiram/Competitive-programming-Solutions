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
ll m,n;
vector <pi> sg(N);
vector <ll> v;
bool can(ll md){
    vector <ll> pre(m + 1, 0);
    for(int i = 0 ; i < md ; i ++){
        pre[v[i]] = 1;
    }
    for(int i = 1 ; i < sz(pre) ; i ++){
        pre[i] += pre[i - 1];
    }
    for(int i = 0 ; i < sz(sg) ; i ++){
        ll nx = sg[i].S - sg[i].F + 1;
        ll one = pre[sg[i].S] - (sg[i].F > 0 ? pre[sg[i].F - 1] : 0 );
        nx -= one;
        if(nx < one) return 1;
    }
    return 0;
}

void solve() {
    cin >> m >> n;
    sg.clear();
    for(int i = 0 ; i < n ; i ++){
        ll x,y;cin >> x >> y;
        sg.pb({x , y});
    }
    ll q;cin >> q;
    v.assign(q , 0);
    for(int i = 0 ; i < q ; i ++)
        cin >> v[i];
    ll l = 0 , r = q + 1, ans = -1;
    while(r - l > 1){
        ll md = (l + r) / 2;
        if(can(md)){
            r = md;
            ans = md;
        }else l = md;
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
