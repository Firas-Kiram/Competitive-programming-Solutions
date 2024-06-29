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

vector <bool> isPrime;
void sieve(ll n){ // N * log log 
    isPrime = vector <bool>(n + 1 , 1);
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 4 ; i < n ; i += 2)
        isPrime[i] = false;
    for(ll i = 3 ; i * i <= n ; i += 2){
        if(!isPrime[i]) continue;
        for(ll j = i * i ; j <= n ; j += i + i){ // i + i no need for the even !
            isPrime[j] = false; // i * i -> bcs we already check the 0 to i - 1
        }
    }
}

vector <ll> factors(ll n){
    vector <ll> res;
    for(int i=2;i * i<=n;i++){
        while(n % i == 0){
            res.pb(i);
            n/=i;
        }
    }
    if(n > 1)
        res.pb(n);
    return res;
}

void solve() {
    ll n , ans = 0;cin >> n;
    vector <ll> v(n , 0);
    map <ll, ll> mp;
    ll nx = 1;
    for(int i = 0 ; i < n ; i ++){
        cin >> v[i];
        if(isPrime[v[i]]){
            mp[v[i]] ++;
            ans += mp[v[i]] / 2;
            mp[v[i]]%=2;
            continue;
        }
        vector<ll> a = factors(v[i]);
        for(ll &x : a){
            mp[x] ++ ;
            ans += mp[x] / 2;
            mp[x] %= 2;
        }   
    }
    nx = 1;
    ll cnt = 0;
    for(auto x : mp){
        if(x.S){
            cnt ++;
            cnt%=3;
            ans += (cnt == 0);
        }
    }
    cout << ans << ln;
}   

int main() {
    io();
    sieve(1e7+500);
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
