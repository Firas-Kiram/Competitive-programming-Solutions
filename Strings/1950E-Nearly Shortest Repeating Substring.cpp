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
void dbgv(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const ll N = 1e5 + 2000;
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; } 
void io() {ios::sync_with_stdio(false);cin.tie(NULL);}
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};

vector<ll> divisors(ll x){
    vector<ll> ret ;
    for(int j = 1 ; j*j<=x ; j++){
        if(x%j) continue;
        ret.pb(j) ;
        if(x/j != j) ret.pb(x/j) ;
    }
    return ret ;
}

ll get(char c){
    ll x = c - 'a';
    return x;
}

void solve() {
    ll n;cin >> n;
    string s;cin >> s;
    vector <ll> d = divisors(n);
    sort(all(d));
    ll rs = n;
    for(auto it : d){
        vector <string> v;
        set <string> st;
        for(int i = 0; i < n ; i += it){
            string a = s.substr(i , it);
            v.pb(a);
            st.insert(a);
        }
        if(sz(st) == 1){
            ckmin(rs , it);
        }else if(sz(st) == 2){
            vector <ll> A(26 , 0) , B(26 , 0);
            auto iter = st.begin();
            ll cnt = 0;
            string x = *iter;iter++;
            string y = *iter;
            ll c = 0;
            for(int i = 0 ; i < sz(x) ; i ++){
                if(x[i]!=y[i])
                    c ++;
            }
            if(c <= 1){
                for(auto x : v){
                    if(*iter == x)
                        cnt ++;
                }
                if(cnt == sz(v) - 1 || cnt == 1){
                    ckmin(rs , it);
                }
            }
        }
    }
    cout << rs << ln;

}

signed main() {
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
