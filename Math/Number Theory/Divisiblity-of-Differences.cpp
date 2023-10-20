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
vector <ll> v[M];

void solve(){
    ll n,k,m;
    cin >> n >> k >> m;
    vector<ll> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
        v[A[i]%m].pb(A[i]);
    }
    for(int i=0;i<m;i++){
        if(sz(v[i])>=k){
            cout << "Yes" << ln;
            for(int j=0;j<k;j++){
                cout << v[i][j] << ' ';
            }
            return;
        }
    }
    cout << "No" << ln;
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
