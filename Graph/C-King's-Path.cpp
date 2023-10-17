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
const ll M = 1e6 + 8432;
const ll MOD = 1073741824;
const int N=1e5+5;
set <pi> graphe;
map <pi,ll> len;
int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};


void solve() { 

    ll x,y,x1,y1;
    cin >> x >> y >> x1 >> y1;
    ll u;cin >> u;
    while(u--){
        ll r,a,b;
        cin >> r >> a >> b;
        for(int i=a;i<b+1;i++){
            graphe.insert(MP(r,i));
        }
    }

    queue<pi> q;
    q.push(MP(x,y));
    ll cnt = 0;
    bool ok = 0;
    while(!q.empty()){
        pair<ll,ll> p = q.front();q.pop();
        for(int i=0;i<8;i++){
            ll di = p.F + dx[i];
            ll dj = p.S + dy[i];
            pair <ll,ll> ne = {di,dj};
            if(graphe.count(ne)&&len.count(ne)==0){
                q.push(ne);
                len[ne] = len[p]+1;
                if(x1 == di && dj == y1){
                    cout << len[p]+1;
                    return;
                }
            }

        }
    }
    cout << -1 << ln;

}   
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
