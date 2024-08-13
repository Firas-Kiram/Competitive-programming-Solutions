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
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
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
ll n , m;
vector <ll> bit[20];
vector <vector <ll>> v(3005 , vector <ll>(3005));
bool vis[3005][3004];
void precount(){
    for(ll i = 0 ; i <= 15 ; i ++){
        for(ll j = 0 ; j < 4 ; j ++){
            bool ok = i & (1LL << j);
            if(ok){
                bit[i].pb(1);
            }else bit[i].pb(0);
        }
        reverse(all(bit[i]));
    }
}

int c = 0 ;
void dfs(ll i , ll j ){
    vis[i][j] = 1;
    c ++ ;
    for(int k = 0 ; k < 4 ; k ++){
        ll di = i + dx[k];
        ll dj = j + dy[k];
        if(di < 0 || dj < 0 || n <= di || dj >= m || vis[di][dj])
            continue;
        vector <ll> a = bit[v[i][j]];
        if(k == 0){
            if(a[2] == 1) continue;
            dfs(di , dj);
        }else if(k == 1){
            if(a[0] == 1) continue;
            dfs(di , dj);
        }else if(k == 2){
            if(a[1] == 1) continue;
            dfs(di , dj);
        }else {
            if(a[3] == 1) continue;
            dfs(di , dj);
        }
    }
}

void solve() {  
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> v[i][j];
        }
    }
    vector <ll> res;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(!vis[i][j]){
                c = 0;
                dfs(i , j);
                res.pb(c);
            }
        }
    }
    sort(all(res) , [&](ll a , ll b){
        return a > b;
    });
    for(auto it : res)
        cout << it << ' ';
}

int main() {
    io();
    precount();
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
