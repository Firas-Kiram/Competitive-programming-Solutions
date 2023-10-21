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
string s,a;
bool vis[M];
int n;
bool good(ll x,vector<ll> v){
    memset(vis,1,sizeof(vis));
    for(int i=0;i<x;i++){
        vis[v[i] - 1] = 0;
    }
    int i = 0,j = 0;
    while(i<n){
        if(vis[i] == 0){
            i++;
            continue;
        }

        if(s[i] == a[j])
            j++;

        if(j == sz(a)) return 1;
        i++;
    }
    return 0;
}


void solve(){
    cin >> s >> a;
    n = sz(s);
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll l = 0,r = n-1,ans = 0;
    int itr = 500;
    while(l<=r&&itr--){
        ll md = (l+r)/2;

        if(good(md,v)){
            ans = md;
            l = md+1;
        }else{
            r = md-1;
        }
    }
    cout << ans <<ln;
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
