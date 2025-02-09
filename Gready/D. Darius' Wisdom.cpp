#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c),end(c)
#define ssize(c) (int)c.size()
#define pb push_back
using ll = long long;
using ld = long double;
using vll = vector<ll>;

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {cerr << ' ' << H;dbg_out(T...);}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<typename T>
void vdbg(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';} 
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

template <class T> 
inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> 
inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

const int MOD = 1e9 + 7;
vector <pair < ll , ll >> res;

void work(set <ll> &a , set <ll> &b){
    while(!a.empty() && !b.empty()){
        ll it = *a.begin() , itt = *prev(b.end());
        if(it > itt) break;
        a.erase(it); a.insert(itt);
        b.erase(itt); b.insert(it);
        res.pb({it , itt});
    }   
}

void solve() {
    ll n;cin >> n;
    vll  v(n);
    set <ll> a , b , c;
    for(int i = 0 ; i < n ; i ++){
        ll x;cin >> x;
        if(x == 0) a.insert(i);
        else if(x == 1) b.insert(i);
        else c.insert(i);
        v[i] = x;
    }
    bool ok = 0;
    while(!ok){
        work(b , a);
        work(c , b);
        bool ok2 = 1;
        if(ssize(a) && ssize(b)) {
            ok2 = (*b.begin() > *prev(a.end()));
        }
        ok = 1;
        if(ssize(b) && ssize(c)){
            ok = (*c.begin() > *prev(b.end()));
        }
        if(!ok || !ok2) ok = 0;
    }
    cout << res.size() << '\n';
    for(auto [x , y] : res) cout << x + 1 << ' ' << y + 1 << '\n';
    res.clear();

}

signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
