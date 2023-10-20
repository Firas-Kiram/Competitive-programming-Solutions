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
vector<ll> v[M];
int visited[M];
char type[M];
void solve(){
    ll n,m;
    cin >> n >> m;
    cin >> type;
    for(int i=0;i<n-1;i++){
        ll a,b;cin >> a >> b;
        a--,b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=0;i<n;i++) visited[i] = -1;
    ll cnt = 0;
    for(int i=0;i<n;i++){
        if(visited[i] == -1){
            queue <ll> q;
            q.push(i);
            char currchar = type[i];
            while(!q.empty()){
                ll x = q.front();
                q.pop();
                visited[x] = cnt;
                for(auto j : v[x]){
                    if(visited[j]==-1 && type[j]==currchar){
                        q.push(j);
                    }
                }
            }
            cnt++;
        }
    }

    for(int i=0;i<m;i++){
        ll a,b;cin >> a >> b;
        char c;cin >> c;
        if(type[a-1]!=type[b-1]){
            cout <<1;
        }else{
            if(type[a-1]==c){
                cout << 1;
            }else{
                if(visited[a-1]!=visited[b-1]){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
