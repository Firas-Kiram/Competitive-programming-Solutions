#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
void watch(vector<ll> v){for (auto x : v)cout<<x<<" ";cout <<'\n';}
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
void io() {ios::sync_with_stdio(false);cin.tie(NULL);}

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
vector <int> v = {2 , 3 , 5 , 7};
ll res = 0 , n;

void rec(int idx , vector <int> a){
    if(idx >= 4)
        return ;
    rec(idx + 1 , a);
    a.pb(idx);
    rec(idx + 1 , a);
    ll L = 1;
    if(a.size() != 3 && a.size() != 4) return ;
    for(auto u : a) L = lcm(v[u] , L);
    if(a.size() == 4)
        res += (n / L);
    else    res -= (n / L);
}

void solve() {
    cin >> n;
    res += n;
    for(int i = 0 ; i < v.size() ;i ++){
        ll x = v[i];
        res -= (n / x);
    }
    for(int i = 0 ; i < v.size() ; i ++){
        for(int j = i + 1 ; j < v.size() ; j ++){
            res += (n / lcm(v[i] , v[j]));
        }
    }
    vector <int> a;
    rec(0 , a);
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}   
