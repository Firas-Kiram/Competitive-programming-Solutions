#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 100;

vector <bool> isPrime;
vector <int> primes;
unordered_set<int> s;

void sieve(ll n){
    isPrime = vector <bool>(n + 1 , 1);
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 4 ; i < n ; i += 2)
        isPrime[i] = false;
    for(ll i = 3 ; i * i <= n ; i += 2){
        if(!isPrime[i]) continue;
        for(ll j = i * i ; j <= n ; j += i + i){
            isPrime[j] = false;
        }
    }
    for(int i = 0 ; i <= n ; i ++)
        if(isPrime[i]) 
            primes.pb(i);
}

void solve() {
    int n;cin >> n;
    vector <int> v(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> v[i];
    }
    for(int i = 0 ; i < n ; i ++){
        int x = v[i];
        for(int j = 0 ; j < primes.size() && primes[j]*1ll*primes[j] <= x ; j ++){
            int k = primes[j];
            if(x % k == 0){
                if(s.count(k)){
                    cout << "YES\n";
                    return;
                }
                s.insert(k);
                while(x % k == 0) x/=k;
            }
        }
        if(x > 1){
            if(s.count(x))
                return void(cout << "YES\n");
            s.insert(x);
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1;
    sieve(1e5);
    cin >> T;
    while (T--) {
        solve();
        s.clear();
    }
    return 0;
}   
