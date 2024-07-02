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
const ll N = 2e5 + 2000;
 
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

// 0 -> X X
// 1 -> X Y
// 2 -> Y X 
// 3 -> Y Y

vector <int> v(105);
ll dp[105][4];
ll n;
ll work(ll i , int nx){
    if(i == n) return 0;
    ll&ret = dp[i][nx];
    if(ret != - 1) return ret;
    if(v[i] == 0){  
        return ret = work(i + 1 , 0);
    }else if(v[i] == 1){
        if(nx == 1 || nx == 0){
            return ret = max(work(i + 1 , 2) + 1 , work(i + 1, nx));
        }
        return ret = work(i + 1 , 0);
    }else if(v[i] == 2){
        if(nx == 2 || nx == 0){
            return ret = max(work(i + 1 , 1) + 1 , work(i + 1 , nx));
        }
        return ret = work(i + 1 , 0);
    }else{
        if(nx == 0){
            return ret = max(work(i + 1 , 1) + 1 , work(i + 1 , 2) + 1);
        }else if(nx == 1) {
            return ret = max(work(i + 1 , 2) + 1 , work(i + 1 , nx));
        }else return ret = max(work(i + 1 , 1) + 1 , work(i + 1 , nx));
    }

}


void solve() {
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> v[i];
    memset(dp , -1 , sizeof(dp));
    cout << n - work(0 , 0);
}
 
int main() {
    io();
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
