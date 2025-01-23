#include<bits/stdc++.h>

using namespace std;
#define pb push_back
using ll = long long;
#define F first
#define S second
#define dbg(x) cout <<#x<<": "<<x<< '\n';
template<typename T>
void watch(vector<T>&v){for(auto&x:v)cout<<x<<" ";cout<<'\n';}
#define all(x) (x).begin(), (x).end()

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }


void solve() {
    ll n , m;cin >> n >> m;
    string s;cin >> s;
    vector <vector <ll>> v(n ,vector <ll>(m));
    vector <ll> r(n , {}) , c(m , {});
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            cin >> v[i][j];
    ll mx = 0;
    for(int i = 0 ; i < n ; i ++){
        ll s = 0;
        for(int j = 0 ; j < m ; j ++) s += v[i][j];
        ckmax(mx , s);
        r[i] = s;
    }
    for(int i = 0 ; i < m ; i ++){
        ll s = 0;
        for(int j = 0 ; j < n ; j ++) s += v[j][i];
        c[i] = s;
    }
    ll d = (s[0] == 'D' ? r[0] : c[0]);
    v[0][0] = -d;
    r[0]-=d;c[0]-=d;
    for(int i = 0 , x = 0 , y = 0 ; i < s.size() ; i ++){
        if(s[i] == 'D') x ++ ;
        else y ++ ;
        ll k = 0;
        if(i == s.size() - 1){
            k = r[x];
        }else {
            if(s[i + 1] == 'D') k = r[x];
            else k = c[y];
        }
        r[x] -= k , c[y] -= k;
        v[x][y] = -k;
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int T = 1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
