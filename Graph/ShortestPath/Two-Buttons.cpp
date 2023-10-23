#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
const ll INF = 1000000000;
const ll MOD = 1073741824;
const ll M = 1e6 + 8432;
const int N= 5e5+10;
const ll EPS = 1e-5;
bool vis[M];
vector<ll> len(M);

void solve(){
    ll n,m;
    cin >> n >> m;
    queue<ll> q;
    int idx = 0;
    q.push(n);
    vis[n] = 1;
    len[n] = 0;
    if(n == m)OUTRET(0);
    if(n>m) OUTRET(n-m);
    ll k = 2e4;
    while(q.size()){
        ll x = q.front();q.pop();
        if(x == m){
            cout << len[x];
            return;
        }

        ll a = x*2;
        if(!vis[a] && a <= k){
            q.push(a);
            len[a] = len[x] + 1;
            vis[a] = 1;
        }
        ll b = x-1;
        if(!vis[b] && b > 0){
            q.push(b);
            len[b] = len[x] + 1;
            vis[b] = 1;
        }
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
