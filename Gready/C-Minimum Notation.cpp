#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
#define ON(n, k) ((n) | (1 << (k)))
#define OFF(n, k) ((n) & ~(1 << (k)))
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define PI 3.1415926535897932384626433832795
const ll INF = 1000000000;
const ll MOD = 1000000007;
const ll M = 1e6 + 8432;
const int N= 2e5+10;
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
 
void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
 
 
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
 
template <typename T>
void print_vector(const vector<T> &a)
{
    for (const auto &x : a)
        cout << x << ' ';
    cout << ln;
}
 
ll get(char c){
    return c - '0';
}
 
void solve(){
	string s;
    ll mn = LLONG_MAX , mx = LLONG_MIN, idx = 0;
    cin >> s;
    int n = (int) sz(s);
    vector <ll> suff(10 , 0) , freq(10 , 0) , ans(10 , 0);
    vector <bool> vis(10 , false);
    for(int i = n - 1; i >= 0 ;i--){
        ll x = get(s[i]);
        freq[x] ++;
        vis[x] = 1;
        bool ok = 1;
        for(int j=0;j<x&&ok;j++){
            if(vis[j]) ok = 0;
        }
        suff[x] += (ok ? 1  : 0);
    }
 
    for(int i=0;i<=9;i++){
        if(suff[i] < freq[i]){
            ll x = freq[i] - suff[i];
            ans[min(i + 1 , 9)] += x;
        }
    }
    for(int i=0;i<=9;i++){
        if(suff[i]) for(int j=0;j<suff[i];j++) cout << i ;
        if(ans[i]) for(int j=0;j<ans[i];j++) cout << i;
    }
    cout << ln;
}
 
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
 
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
