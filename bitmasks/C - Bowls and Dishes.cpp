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
typedef long long int lli;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define mem(a, n) memset((a),n,sizeof (a))
#define dbg(x) cout <<#x<<": "<<x<< ln;
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
#define ln '\n'
#define PI 3.1415926535897932384626433832795
const ll INF = 1000000000;
const ll MOD = 1000000007;
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

void solve(){
	ll n,m;
	cin >> n >> m;
	vector <pair<int , int>> v(m);
	for(int i = 0 ; i < m ; i += 1){
		cin >> v[i].F >> v[i].S; 
	}
	int k;cin >> k;
	vector <pair<int , int>> ball(k);
	for(int i = 0; i < k ; i += 1){
		cin >> ball[i].F >> ball[i].S;
	}
	int mx = 0;
	for(int i = 0 ; i < (1 << k) ; i += 1){
		vector<int> tmp(n + 1);
		int cnt = 0;
		for(int j = 0 ; j < k ; j += 1){
			int a = ball[j].F , b = ball[j].S;
			if(i&(1 << j)){
				tmp[a] += 1;
			}else tmp[b] += 1;
		}
		for(int j = 0 ; j < sz(v) ; j += 1){
			if(tmp[v[j].F] >= 1 && tmp[v[j].S] >= 1)
				cnt += 1;
		}
		mx = max(cnt , mx);
	}
	cout << mx << ln;
}	

int main() {
    io();
    int T = 1;
	//cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
