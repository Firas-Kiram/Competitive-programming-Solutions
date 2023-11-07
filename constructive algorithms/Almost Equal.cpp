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
int dx[8] = {1,-1,0,0};
int dy[8] = {0,0,1,-1};


void solve(){
    int n;
    cin >> n;
    if(!(n&1))OUTRET("NO");
    vector<int> v(n*2);
    if(n==1){cout << "YES" << ln << 1 << ' ' << 2 << ln; return;}
    v[0] = 1;
    v[n] = 2;
    int x = 3;
    for(int i=1;i<n;i++){
        if(i%2 == 0){
            v[n+i] = x+1;
            v[i] = x;
        }else{
            v[i] = x+1;
            v[n+i] = x;
        }
        x+=2;
    }
    cout << "YES" << ln;
    for(auto i : v) cout << i << ' ';
}


int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
