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
ll n,m;

void solve(){
	cin >> n ;
	vector <ll> v(n);
	map <ll ,ll> freq;
	for(int i=0;i<n;i++){
		cin >> v[i];
		freq[v[i]]++;
	}
	if(is_sorted(all(v))) OUTRET(0);
	freq[v.back()]--;
	int idx = n - 1;
	for(int i= n-1;i>= 1;i--){
		if(v[i] >= v[i - 1]){
			freq[v[i - 1]]--;
			idx = i - 1;
		}else{
			break;
		}
	}
	int o = 0;
	set <int> s;
	for(int i= n - 1; i >= 0;i--){
		if(freq[v[i]] >= 1){
			o = i;
			s.insert(v[i]);
			while(o >= 0){
				s.insert(v[o]);
				o--;
			}
			break;
		}
	}
	cout << sz(s) << ln;
	
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
