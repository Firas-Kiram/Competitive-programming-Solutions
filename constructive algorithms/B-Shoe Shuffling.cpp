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
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
const ll INF = 1000000000;
const ll MOD = 1073741824;
const ll M = 1e6 + 8432;
const int N= 5e5+10;
const ll EPS = 1;

void solve(){
	ll n;cin >> n;
	vector <ll> v(n);
	map <ll , ll> freq;
	map <ll, vector <ll>> adj;
	for(int i=0;i<n;i++){
		cin >> v[i];
		freq[v[i]]++;
		adj[v[i]].pb(i);
	}
	ll ok = 1;
	for(auto i : freq){
		if(i.S <= 1){
			ok = 0;
			break;
		}
	}
	if(!ok){
		OUTRET(-1);
	}else{
		map <ll , ll >ans;
		for(auto i : adj){
			vector <ll> temp;
			for(auto j : i.S) {
				temp.pb(j);
			}
			if(sz(temp) == 2){
				ans[temp[1]] = temp[0];
				ans[temp[0]] = temp[1];
			}else{
				for(int i=0;i<sz(temp) - 1;i++){
					ans[temp[i]] = temp[i + 1];
				}
			}
			ans[temp[sz(temp) - 1]] = temp[0];
		}
		for(auto i : ans){
			cout << i.S+1 << ' ';
		}
		cout << ln;
	}
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
