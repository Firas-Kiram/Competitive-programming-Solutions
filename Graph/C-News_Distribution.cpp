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
const ll M = 1e6 + 8432;
const ll MOD = 1073741824;
vector <ll> edg[M];
bool vis[M];
 
 
void solve() { 
    ll n,m;
    cin >> n >> m;
    while(m--){
        ll x;cin >> x;
        vector <ll> v(x+1);
        for(int i=1;i<=x;i++){
            cin >>v[i];
        }
        for(int i=1;i<x;i++){
            edg[v[i]].pb(v[i+1]);
            edg[v[i+1]].pb(v[i]);
        }
 
    }
    ll arr[n+1];
    for(int i=1;i<=n;i++){
        vector <ll> st;
        if(!vis[i]){
            queue<ll> q;
            q.push(i);
            while(!q.empty()){
                ll x = q.front();
                q.pop();
                if(vis[x]) continue;
                vis[x] = 1;
                st.pb(x);
 
                for(auto j : edg[x]){
                    if(!vis[j]){
                        q.push(j);
                     }
                }
            }
            for(auto g : st)  arr[g] = sz(st);
 
        }
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] << ' ';
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
