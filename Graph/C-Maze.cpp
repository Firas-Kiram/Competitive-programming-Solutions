#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<endl;  
#define no cout<<"NO"<<endl;
#define sz(v) ((int)((v).size()))
const ll size_arr = 1e6 + 8432;
ll n,m,k;
char g[502][502];
bool vis[502][502];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};


void dfs(ll r,ll l){

    if(r < 0 || n <= r || 0 > l || l >= m || vis[r][l] || g[r][l]=='#' ) return;
    vis[r][l] = true;
    for(int i=0;i<4;i++){
        dfs(r+dx[i],l+dy[i]);
    }

    if(k>0){
        k--;
        g[r][l] = 'X';
    }

}


void solve() {

    cin>>n>>m>>k;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='.'){
                x = i;
                y = j;
            }
        }
    }

    dfs(x,y);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }

}


int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int T=1;
    //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
