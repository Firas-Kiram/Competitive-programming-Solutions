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
bool col[M];
bool ok = 1;

void dfs(ll node,vector<ll> v[],int c){
    vis[node] = 1;
    col[node] = c;
    for(auto j : v[node]){
        if(!vis[j]){
            dfs(j,v,c ^ 1);
        }else if(col[j] == c){
            ok = 0;
        }
    }

}


void solve(){
    ll n;cin >> n;
    ll l;cin >> l;
    while(n != 0){
        vector<ll> v[n+1];
        for(int i=0;i<l;i++){
            ll a,b;cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ok = 1;
        memset(vis,0,sizeof(vis));
        memset(col,0,sizeof(col));
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,v,0);
            }
        }
        if(!ok){
            cout << "NOT BICOLORABLE." << ln;
        }else{
            cout << "BICOLORABLE." << ln;
        }
        cin >> n;
        if(n!=0)
            cin >> l;
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
