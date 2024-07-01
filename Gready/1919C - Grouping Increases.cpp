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
const ll N = 1e5 + 2000;

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

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n , 0) , a = {0}, b = {0};
    for(int i = 0 ; i < n ; i ++)
        cin >> v[i];
    for(int i = 0 ;i < n ; i ++){
        if(v[i] > b.back() && v[i] > a.back()){
            if(a.back() > b.back()){
                b.pb(v[i]);
            }else a.pb(v[i]);
        }else if(v[i] < b.back() && v[i] < a.back()){
            if(a.back() < b.back()) a.pb(v[i]);
            else b.pb(v[i]);
        }else if(v[i] > b.back() && v[i] < a.back()){
            a.pb(v[i]);
        }else if(v[i] < b.back() && v[i] > a.back()){
            b.pb(v[i]);
        }
    }
    ll tot = 0;
    for(int i = 1 ; i < sz(b) - 1 ; i ++){
        tot += (b[i] < b[i + 1]);
        // if(b[i] < b[i + 1])
    }
    for(int i = 1 ; i < sz(a) - 1 ; i ++){
        tot += (a[i] < a[i + 1]);
    }
    cout << tot << ln;
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
