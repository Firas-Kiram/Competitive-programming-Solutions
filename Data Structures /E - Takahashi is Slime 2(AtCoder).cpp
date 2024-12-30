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
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

const ll N = 2e5 + 100;
vector <vector <bool>> vis;
vector <vector <ll>> v;
ll h , w , x , P , Q;

bool valid(ll i ,ll j){
    return (i >= 0 && i < h && j >= 0 && j < w);
}

struct Compare {
    bool operator()(const pair<ll, pi>& a, 
                    const pair<ll , pi>& b) {
        return a.first > b.first;
    }
};

void solve() {
    cin >> h >> w >> x >> P >> Q;
    v = vector <vector <ll>>(h , vector <ll>(w));
    vis = vector <vector <bool>>(h , vector <bool>(w));
    P -- , Q -- ;
    for(int i = 0 ; i < h ; i ++){
        for(int j = 0 ; j < w ; j ++){
            cin >> v[i][j];
            vis[i][j] = 0;
        }
    }
    priority_queue <pair <ll , pi> , vector <pair <ll , pi>> , Compare> pq;
    pq.push({0 , {P , Q}});
    ll k = v[P][Q];
    vis[P][Q] = 1;
    while(pq.size()){
        const auto u = pq.top();pq.pop();
        if(u.F >= (k + x - 1) / x  ) break;
        k += u.F;
        for(int i = 0 ; i < 4 ; i ++){
            ll di = u.S.F + dx[i];
            ll dj = u.S.S + dy[i];
            if(valid(di , dj) && !vis[di][dj]){
                vis[di][dj] = 1;
                pq.push({ v[di][dj] , {di , dj}});
            }
        }
    }
    cout << k << '\n';
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
