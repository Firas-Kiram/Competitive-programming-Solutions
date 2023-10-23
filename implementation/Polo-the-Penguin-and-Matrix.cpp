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

void solve(){
    ll n,m,d;
    cin >> n >> m >> d;
    vector<vector<ll>>v(n,vector<ll>(m));
    vector <pair <pi,ll>> p;
    vector<vector<ll>>A(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
            p.pb({{i,j},v[i][j]});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll c = v[i][j];
            ll o = 0;
            for(int k=0;k<sz(p);k++){
                if(i==p[k].F.F && j == p[k].F.S) continue;
                ll q = abs(p[k].S - v[i][j]);
                if(q%d != 0) OUTRET(-1);
                o += q/d;
            }
            v[i][j] = o;
        }
    }
    ll mn = LLONG_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mn = min(mn , v[i][j]);
        }
    }
    cout << mn << ln;
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
