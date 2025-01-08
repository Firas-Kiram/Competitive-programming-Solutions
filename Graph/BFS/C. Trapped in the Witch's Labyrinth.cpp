#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
template<typename T>
void watch(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
void io(){ios::sync_with_stdio(false);cin.tie(NULL);}
#define all(x) (x).begin(), (x).end()

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }


ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
const ll N = 2e5 + 100;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

vector <vector <char>> v;

ll n , m;

bool valid(ll i , ll j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

pi next(ll i , ll j){
    char c = v[i][j];
    if(c == 'R') j ++ ;
    else if(c == 'L') j -- ;
    else if(c == 'U') i --;
    else if(c == 'D') i ++ ;
    else return {-100 , -100};
    return {i , j};
}

void solve() {
    cin >> n >> m;
    v = vector <vector <char>> (n , vector <char>(m , false));
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j++)
            cin >> v[i][j];
    set <pi> s;
    bool vis[n][m];
    memset(vis , false , sizeof vis);
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(vis[i][j] || v[i][j] == '?') continue;
            queue <pi> q;
            q.push({i , j});
            vis[i][j] = 1;
            vector <pi> a;
            bool ok = 0;
            while(q.size()){
                pi p = q.front();q.pop();a.pb(p);
                pi nex = next(p.F , p.S);
                if(!valid(nex.F , nex.S)){
                    ok = 1;
                    break;
                }else {
                    if(v[nex.F][nex.S] == '?') continue;
                    if(s.find(nex)!=s.end()) ok = 1;
                    if(!vis[nex.F][nex.S]){
                        q.push(nex);
                        vis[nex.F][nex.S] = 1;
                    }
                }
            }
            if(ok) for(auto it : a) s.insert(it);
        }
    }
    ll res = n * m - s.size();
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(v[i][j] != '?') continue;
            bool ok = 0;
            for(int k = 0 ; k < 4 ; k ++){
                ll di = i + dx[k] , dj = j + dy[k];
                if(valid(di , dj)){
                    if(s.find({di , dj}) == s.end()) ok = 1;
                }
            }
            if(!ok) res -- ;
        }
    }
    cout << res << '\n';
}


signed main() {
    io();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
