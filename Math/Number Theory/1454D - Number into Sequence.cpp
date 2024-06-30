/** * * * * * * * * * * * * * * * **\
 *                                 *
 *   See its changed now you are   *
 *   not around i'm not the same,  *
 *    but! i hope you are proud,   *
 *       until we meet again       *
 *                                 *
\** * * * * * * * * * * * * * * * **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define dbg(x) cout <<#x<<": "<<x<< ln;
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
const ll INF = 1000000000;
const ll MOD = 1e9 + 7;
const ll M = 1e6 + 8432;
const ll N = 1000000000000;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<pair<ll,ll>> primeFactorze(ll n)
{
    vector<pair<ll,ll>> arr;
    for(ll i=2;i*i<=n;i++)
    {
        int w=0;
        while(n%i==0)
        {
            w++;
            n/=i;
        }
        if(w)arr.push_back({i,w});
    }
    if(n>1)arr.push_back({n,1});
    return arr;
}

void solve() {
   ll n;cin >> n;
   vector <pi> v = primeFactorze(n);
    if(sz(v) == 1 && v[0].S == 1) {
        cout << 1 << ln;
        cout << v[0].F << ln;
        return;
    }
    sort(all(v));
    ll nx = 0 , res = 1 , mx = -1 , j = 0;
    for(int i = 0 ; i < sz(v) ; i ++){
        if(ckmax(mx,v[i].S)){
            j = i;
        }
    }
    for(int i = 0 ; i < sz(v); i ++){
        if(i == j) continue;
        ll idx = 0;
        while(idx < v[i].S) res*=v[i].F , idx ++;
    }
    if(v[j].S == 1){
        cout << 1 << ln;
        cout << res*v[j].F << ln;
        return;
    }
    cout << v[j].S << ln;
    nx = 1;
    while(nx < v[j].S){cout << v[j].F << ' ';nx++;}
    cout << res*v[j].F << ln;
}   

int main() {
    io();
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
