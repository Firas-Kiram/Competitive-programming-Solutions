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

vector <ll> divisor(ll n){
    vector<ll> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            if(i != 1)
                ans.pb(i);
            ans.pb(n/i);
        }
    }
    return ans;
}


void solve(){
    ll x,y;
    cin >> x >> y;
    for(int i=x;i<=y;i++){
        if(i!=2 && i%2==0){
            cout << 2 << ' ' << i-2  << ln;
            return;
        }
        vector<ll> v = divisor(i);
        sort(all(v));
        if(sz(v)){
            if(i - v[0] > 0 ){
                cout << v[0] << ' ' << i - v[0] << ln;
                return;
            }
        }
        v.clear();
    }
    cout << -1 << ln;
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
