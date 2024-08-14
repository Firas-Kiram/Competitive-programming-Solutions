#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define ln '\n'
#define OUTRET(...) { OUT(__VA_ARGS__); return; }
#define OUT(...) cout << __VA_ARGS__ << '\n'
#define dbg(x) cout <<#x<<": "<<x<< ln;
void dbgv(vector<ll> v){for (auto x : v)cout<<x<<" ";cout <<ln;}
#define all(x) (x).begin(), (x).end()
#define yes cout<<"YES"<<ln;
#define no cout<<"NO"<<ln;
#define sz(v) ((int)((v).size()))
// const ll INF = 0x3f3f3f3fm3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const ll N = 1e5 + 2000;
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; } 
void io() {ios::sync_with_stdio(false);cin.tie(NULL);}
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
bool ok = 0;
char v[1005][1005];
bool vis[1005][1005];
ll n , m ;

void solve() {
    cin >> n >> m;
    pi st , en;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> v[i][j];
            if(v[i][j] == 'A')
                st = {i , j};
            else if(v[i][j] == 'B') en = {i , j};
        }
    }
    queue <pi> q;
    q.push({st.F , st.S});
    vis[st.F][st.S] = 1;
    vector <vector <pi>> par(n , vector <pi>(m));
    par[st.F][st.S] = {-1 , -1};
    while(sz(q)){
        pi A = q.front();q.pop();
        if(A.F == en.F && A.S == en.S){
            ok = 1;
            break;
        }
        for(int i = 0 ;i < 4 ; i ++){
            ll di = A.F + dx[i];
            ll dj = A.S + dy[i];
            if(di >= n || dj >= m || di < 0 || dj < 0 || vis[di][dj] || v[di][dj] == '#')
                continue;
            q.push({di , dj});
            vis[di][dj] = 1;
            par[di][dj] = {A.F , A.S};
        }
    }
    if(!ok) OUTRET("NO");
    vector <pi> ans = {{en.F , en.S}};
    ll x = en.F , y = en.S;
    while(par[x][y].F!=-1 && par[x][y].S!=-1){
        pi idx = par[x][y];
        x = idx.F;
        y = idx.S;
        ans.pb(idx);
    }
    vector <char> a;
    for(int i = 0 ; i < sz(ans) - 1; i ++){
        if(ans[i].F == ans[i + 1].F){
            if(ans[i].S > ans[i + 1].S) a.pb('R');
            else a.pb('L');
        }else {
            if(ans[i].F > ans[i + 1].F) a.pb('D');
            else a.pb('U');
        }
    }
    yes
    reverse(all(a));
    cout << sz(a) << ln;
    for(auto it : a)
        cout << it;
    
}

int main() {
    io();
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
} 
