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
int dx[8] = {1,-1,0,0};
int dy[8] = {0,0,1,-1};

void solve(){
    int n;cin >> n;
    vector <int> v(n);
    vector <int> adj[105];
    set <int > s,st;
    for(int i=0;i<n;i++){
        cin >> v[i];
        adj[v[i]].pb(i);
        s.insert(v[i]);
    }

    for(auto i : s){
        if(sz(adj[i])>=2){
            st.insert(i);
        }
    }
    if(sz(st)>=2){
        vector<bool> vis(n+1,false);
        v[adj[*(st.begin())][0]] = 1;vis[adj[*(st.begin())][0]] = 1;
        v[adj[*(st.begin())][1]] = 2;vis[adj[*(st.begin())][1]] = 1;
        v[adj[*next(st.begin())][1]] = 1;vis[adj[*next(st.begin())][1]] = 1;
        v[adj[*next(st.begin())][0]] = 3;vis[adj[*next(st.begin())][0]] = 1;
        for(int i=0;i<n;i++){
            if(vis[i]){
                cout << v[i] << ' ';
            }else cout << 1 << ' ';
        }
        cout << ln;
    }else cout << -1 << ln;
}


int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
