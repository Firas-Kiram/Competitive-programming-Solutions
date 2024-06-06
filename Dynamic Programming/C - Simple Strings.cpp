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

char get(char c , char a){
	if(c == 'z' && a == 'z') return 'y';
	if(c == 'z' && a == 'y') return 'x';
	if(c == 'z' && a == 'x') return 'y';
	for(int i = 'a' ; i <= 'z' ; i += 1){
		if(c != (char)i && a != (char)i) return (char)i;
	}
}


void solve(){
	string s;cin >> s;
	int n = sz(s);
	for(int i = 0 ; i < n ; i += 1){
		if(i + 2 < n && s[i] == s[i + 1] && s[i] == s[i + 2]){
			char c = get(s[i + 1] , s[i + 1]);
			s[i + 1] = c;
			i += 1;
		}else if(i + 1 < n && s[i] == s[i + 1]){
			if(i - 1 >= 0){
				char c = get(s[i - 1] , s[i + 1]);
				s[i] = c;
			}else{
				char c = get(s[i + 1] , s[i + 1]);
				s[i] = c;
			}
		}
	}
	cout << s << ln;
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

