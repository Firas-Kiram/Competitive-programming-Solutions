#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
template<typename T>
void watch(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
void io(){ios::sync_with_stdio(false);cin.tie(NULL);}
#define all(x) (x).begin(), (x).end()
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
const int N = 3e5 + 5;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
ll h , w , d;

bool valid(ll i , ll j){
    return (i >= 0 && i < h && j >= 0 && j < w);
}

void solve() {
    cin >> h >> w >> d;
    char v[h][w];
    ll a[h][w];
    for(int i = 0 ; i < h ; i ++)
        for(int j = 0 ; j < w ; j ++)
            cin >> v[i][j] , a[i][j] = INF;
    queue <pair <pi , ll>> q;
    for(int i = 0 ; i < h ; i ++)
        for(int j = 0 ; j < w ; j ++)
            if(v[i][j] == 'H')
                q.push({{i , j} , 0});
    while(!q.empty()){
        pair <pi , ll> p = q.front();q.pop();
        ckmin(a[p.F.F][p.F.S] , p.S);
        for(int k = 0 ; k < 4 ; k ++){
            ll di = p.F.F + dx[k];
            ll dj = p.F.S + dy[k];
            if(valid(di , dj) && a[di][dj] > a[p.F.F][p.F.S] && v[di][dj] == '.'){
                q.push({{di , dj} , p.S + 1});
            }
        }
    }
    ll res = 0;
    for(int i = 0 ; i < h ; i ++)
        for(int j = 0 ; j < w ; j ++)
            res += (a[i][j] <= d);
    cout << res << '\n';
}   


signed main() {
    #ifndef ONLINE_JUDGE
       freopen("input.in", "r", stdin);
       freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    io();
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}      
