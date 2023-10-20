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
ll n,k;
ld A[M];

bool good(ld x){
    ll c = 0;
    for(int i=0;i<n;i++){
        if(A[i]>=x){
            c+=floor(A[i]/x);
        }
    }
    return c>=k;
}


void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++) 
        cin >> A[i];
    ld l = 0.0,r = 1,ans = 0;
    while(good(r)) r*=2;
    ll itr = 300;
    while(l<=r&&itr--){
        ld md = (l+r)/2;

        if(good(md)){
            l = md;
            ans = md;
        }else{
            r = md;
        }
    }
    cout << fixed << setprecision(6) <<ans << ln;
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
