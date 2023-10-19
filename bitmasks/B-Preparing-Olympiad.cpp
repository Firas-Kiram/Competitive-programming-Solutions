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
vector <vector<ll>> subsets;

void search(int k,int n,vector<ll> &subset) {
    if (k == n) {
        subsets.pb(subset);
        return;
    } else {
        search(k+1,n,subset);
        subset.push_back(k);
        search(k+1,n,subset);
        subset.pop_back();
    }
}

void solve(){
    ll n,l,r,x;
    cin >> n >> l >> r >> x;
    vector<ll> subset;
    search(0,n,subset);
    vector<ll> c(n);
    for(int i=0;i<n;i++) cin >> c[i];
    ll ans = 0;
    for(auto i : subsets){
        ll sum = 0,mn = INF,mx = -INF,cnt = 0;
        for(auto j : i){
            cnt++;
            mn = min(mn,c[j]);
            mx = max(mx,c[j]);
            sum+=c[j];
        }
        if(mx - mn >= x && sum >= l && sum <= r && cnt >= 2) ans++;
    }
    cout << ans << ln;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
