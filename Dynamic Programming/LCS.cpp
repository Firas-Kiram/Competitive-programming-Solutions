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
ll dp[3005][3005];
string a,b;

ll work(ll i ,ll j){
    if(i == a.size()||j==b.size()) 
        return 0;
    ll&ret = dp[i][j];
    if(ret != -1) return ret;
    if(a[i]==b[j]){
        return ret = work(i + 1 , j + 1) + 1;
    }
    return ret = max(work(i + 1 , j) , work(i , j + 1));
}

void print(ll i , ll j){
    if(i == a.size()||j==b.size())
        return;
    ll&ret = dp[i][j];
    if(a[i] == b[j]){
        cout << a[i];
        print(i+1,j+1);
        return;
    }
    if(ret == work(i + 1 , j)) print(i+1, j);
    else if(ret == work(i , j + 1)) print(i ,j+1);
}

void solve() {
    cin >> a >> b;
    memset(dp , -1 , sizeof(dp));
    work(0 , 0);
    print(0 , 0);
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
