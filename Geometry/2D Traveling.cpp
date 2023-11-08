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

ll calc(pi a,pi b){
    return abs(a.F - b.F) + abs(a.S - b.S);
}

void solve(){
    int n,k,a,b;
    cin >> n >> k >> a >> b;
    pi A[n+1];
    for(int i=0;i<n;i++){
        cin >> A[i].F >> A[i].S;
    }
    pi st = A[a-1];
    pi end = A[b-1];
    if(k == 0){
        cout << calc(st,end) << ln; 
        return;
    }
    ll mn = 1e18,mn2 = 1e18;
    for(int i=0;i<k;i++){
        mn = min(mn,(ll)calc(st,A[i]));
        mn2 = min(mn2,(ll)calc(end,A[i]));
    }
    cout << min(mn+mn2,calc(st,end)) << ln;
}


int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
