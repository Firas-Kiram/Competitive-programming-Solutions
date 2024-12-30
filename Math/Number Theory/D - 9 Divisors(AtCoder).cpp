#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
template<typename T>
void watch(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
void io(){ios::sync_with_stdio(false);cin.tie(NULL);}
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
const ll N = 2e5 + 100;

vector <bool> isPrime;
vector <ll> primes;
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
    for(ll i = 1 ; i <= n && (i * i * 2 * 2) <= 4e12 + 10 ; i ++){
        if(isPrime[i]) primes.pb(i);
    }
}

void solve() {
    ll m = 4e6 + 100;
    sieve(m);
    vector <ll> pre(primes.size() , 0);
    ll n , res = 0;cin >> n;
    for(auto it : primes){
        if(it * it * it * it * it * it * it * it > n) break;
        res ++;
    }
    for(ll i = 0 ; i < primes.size() ; i ++) pre[i] = (primes[i] * primes[i]);
    for(int i = 0 ; i < primes.size() && primes[i] * primes[i] <= n ; i ++){
        ll p = primes[i];
        ll x = (n / (p * p));
        ll idx = upper_bound(all(pre) , x) - pre.begin() - 1;
        res += max(idx - i , 0ll);
    }
    cout << res << '\n';
}



signed main() {
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    io();
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}      
