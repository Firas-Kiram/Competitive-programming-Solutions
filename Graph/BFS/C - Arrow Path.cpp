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
	

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool valid(int x,int y,ll n){
	return x < 2 && x >= 0 && y < n && y >= 0;
}

void solve(){
	ll n;
	cin >> n;
	vector <vector<char>> v(2 , vector <char>(n));
	for(int i=0;i<2;i++)
		for(int j=0;j<n;j++)
			cin >> v[i][j];

	bool vis[2][n];
	bool A[2][n];
	for(int i=0;i<2;i++) memset(vis,false,sizeof(vis));
	for(int i=0;i<2;i++) memset(A,false,sizeof(A));
	queue <pair <int , pair <int,int>>> q;
	q.push({1,{0,0}});
	vis[0][0] = true;
	while(!q.empty()){
		auto p = q.front();q.pop();
		if(p.F == 1){
			for(int i=0;i<4;i++){
				int di = p.S.F + dx[i];
				int dj = p.S.S + dy[i];
				if(valid(di,dj,n) && !vis[di][dj]){
					ll x = p.F ^ 1;
					q.push({x,{di,dj}});
					vis[di][dj] = true;
					A[di][dj] = x;
				}
			}
		}else{
			ll x = p.S.F , y = p.S.S;
			if(v[x][y] == '<'&& !vis[x][y - 1]){
				q.push({(p.F ^ 1),{x,y - 1}});
				vis[x][y - 1] = 1;
				A[x][y] = p.F ^ 1;
			}else if(v[x][y] == '>' && !vis[x][y + 1]){
				q.push({(p.F ^ 1),{x,y + 1}});
				vis[x][y + 1] = 1;
				A[x][y] = p.F ^ 1;
			}
		}
	}
	cout << (vis[1][n - 1] ? "YES" : "NO") << ln;

}

int main() {

    io();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
