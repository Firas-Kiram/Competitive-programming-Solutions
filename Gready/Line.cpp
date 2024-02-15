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
#define dbg(x)              if(debug) {cout<<#x<<" = "<<x<<endl;}
#define PI 3.1415926535897932384626433832795
const ll INF = 1000000000;
const ll MOD = 1000000007;
const ll M = 1e6 + 8432;
const int N= 5e5+10;


void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}


ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

inline void print_vector(vector<ll> &a)
{
    for (auto &x : a)
        cout << x << ' ';
    cout << ln;
}


void solve(){
	ll n;
	string s;
	cin >> n >> s;
	vector <ll> pre(n , 0) , setik(n , 0);
	map <ll , pi> mp;
	vector <pi> v;
	ll sum = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'L') v.pb({i,i});
		else v.pb({n - (i + 1) , i});
		mp[i] = {i , (n - (i+1))};
		sum += (s[i] == 'L' ? i : (n - (i+1)));
	}
	sort(all(v));
	pre[0] = (s[v[0].S] == 'L' ? mp[ v[0].S ].S : mp[v[0].S].F);
	setik[0] = (s[v[0].S] == 'L' ? mp[ v[0].S].F : mp[v[0].S].S);
	for(int i=1;i<n;i++){
		if(s[v[i].S] == 'L'){
			setik[i] += setik[i - 1] + mp[v[i].S].F;
			pre[i] += pre[i - 1] + mp[v[i].S].S;
		}else{
			setik[i] += setik[i - 1] + mp[v[i].S].S;
			pre[i] += pre[i - 1] + mp[v[i].S].F;
		}
	}
	vector <ll> mx(n , 0);
	ll mxv = -1;
	for(int i=0;i<n;i++){
		mxv = max(mxv , pre[i] - setik[i]);
		mx[i] = mxv;
	}
	for(int i=0;i<n;i++){
		cout << max(sum + mx[i] , sum) << ' ';
	}
	cout << ln;

}


int main() {
 
    io();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
	 
    return 0;
}
