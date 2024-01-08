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
int dx[8] = {1,-1,0,0};
int dy[8] = {0,0,1,-1};
vector <vector <char>> arr(105 , vector <char>(105));
ll n;


ll calc(ll x,ll y,ll a,ll b){
	return ((x - a)*(x - a)) + ((y - b)*(y - b));
}


bool valid(ll i,ll j){
	return i<n && i>=0 && j<n && j>=0;
}

void dfs(ll i,ll j,set <pi>&S){	
	if(!valid(i,j))return;
	for(int k=0;k<4;k++){
		ll di = i + dx[k];
		ll dj = j + dy[k];
		if(valid(di ,dj) && arr[di][dj] == '0'){
			S.insert({di , dj});
			arr[di][dj] = '1';
			dfs(di ,dj , S);
		}
	}
}



void solve(){
	ll x,y,a,b;cin >> n >> x >> y >> a >> b;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	set <pi> A , S;
	S.insert({x - 1 , y - 1});
	dfs(x - 1 , y - 1 , S);
	for(auto i : S){
		if(i.F == a - 1 && i.S == b - 1){
			OUTRET(0);
		}
	}
	A.insert({a - 1,b - 1});
	dfs(a - 1 , b - 1 , A);
	ll mn =  calc(x,y,a,b);
	for(auto i : S){
		for(auto j : A){
			mn = min(calc(i.F , i.S , j.F , j.S) , mn);
		}
	}
	cout << mn << ln;
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
