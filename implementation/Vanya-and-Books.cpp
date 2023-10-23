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
ll C [] = {9,99,999,9999,99999,999999,9999999,99999999,999999999};
ll A [] = {9,90,900,9000,90000,900000,9000000,90000000,900000000};

void solve(){
    ll n;
    cin >> n;
    if(n<10)OUTRET(n);
    string s = "";
    s = to_string(n);
    int m = sz(s);
    ll ans = 0;
    int i = (m-2);
    ans += (n - C[i]) * m;
    for(int i=(m-2);i>=0;i--){
        ans += (A[i] * (i+1));
    }
    cout << ans << ln;
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
