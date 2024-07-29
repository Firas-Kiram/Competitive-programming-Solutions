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
const ll MX = 4005;
vector <ll> adj[MX];
vector <ll> W , A;
string s;

void dfs(ll node ,ll anc){
    for(ll x : adj[node]){
        if(x != anc){
            dfs(x , node);
            A[node] += A[x] + 1;
            W[node] += W[x] + (s[x - 1] == 'W');
        }
    }
}


void solve() {
    ll n;cin >> n;
    vector <ll> v(n);
    W.assign(n + 1 , 0);
    A.assign(n + 1 , 0);
    for(int i = 2 ; i <= n ; i ++){
        ll x;cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    cin >> s;
    dfs(1 , -1);
    ll tot = 0;
    for(int i = 1 ; i <= n ; i ++){
        ll x = W[i] + (s[i - 1] == 'W');
        ll y = A[i] + 1;
        if(y % 2 == 0 && x == y / 2)
            tot ++;
    }
    cout << tot << ln;
    for(int i = 1; i <= n ; i ++)
        adj[i].clear();
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
