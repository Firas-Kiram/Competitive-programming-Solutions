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
const ll INF = 1000000000;
const ll MOD = 1073741824;
const ll M = 1e6 + 8432;
const int N= 5e5+10;
const ll EPS = 1e-5;
const int P = 105;
vector <vector<char>> v(P,vector <char>(P));
bool vis[P][P];
int n,m;

int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};

bool good(int i,int j){
    return i<n&&i>=0&&j<m&&j>=0&&v[i][j] == '@';
}

void dfs(int i,int j){
    for(int k=0;k<8;k++){
        int a = i + dx[k];
        int b = j + dy[k];
        if(good(a,b)&&!vis[a][b]){
            vis[a][b] = 1;
            dfs(a,b);
        }
    }
}

void solve(){
    cin >> n >> m;
    while(!(n==0&&m==0)){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    int cmp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&& v[i][j] == '@'){
                dfs(i,j);
                cmp++;
            }
        }
    }
    cout << cmp << ln;
    cin >> n >> m;
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
