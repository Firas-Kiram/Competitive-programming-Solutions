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
const int N= 2e5+10;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
	string s;cin >> s;
	int m = int(sz(s)) , idx = 0;
	vector <bool> vis(m , 0);
	stack <pair < char , int >> st;
	st.push({'$' , -1});
	for(int i=0;i<m;i++){
		pair <char , int> A = st.top();
		// cout << A.F << ln;
		if(s[i] == s[i + 1]){
			vis[i] = vis[i + 1] = 1;
			i += 1;
		}else if(s[i] == A.F ){
			vis[i] = vis[A.S] = 1;
			st.pop();
		}else{
			st.push({s[i] , i});
		}
	}
	for(int i=0;i<m;i++){
		if(!vis[i]) cout << s[i];
	}
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
