#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<endl;  
#define no cout<<"NO"<<endl;
#define sz(v)               ((int)((v).size()))
 
 
 
const ll size_arr = 1e6 + 8432;
ll c[size_arr];
ll res = 0; 
 
vector<ll> edges[100005];
bool vis[100005];
 
ll dfs(ll n) {
 
    ll mn = c[n];
    vis[n] = 1;
    
    for (ll i: edges[n]) {
        if (!vis[i]) {
            mn = min(mn, dfs(i));
        }
    }
    return mn;
}
 
void solve() {
    ll n,m;
    cin >>n>> m;
    
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    for (ll i=0;i<m;i++) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            res += dfs(i);
        }
    }
    
    cout <<res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
 
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
 
    return 0;
}
