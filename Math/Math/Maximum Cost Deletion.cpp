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
vector<char> adj[M];
 
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    string s;cin >> s;
    if(b<0){
        vector<int> one,zero;
        for(int i=0;i<sz(s);i++){
            int o = i;
            while(s[o] == s[o+1] && o+1 < sz(s)){
                o++;
            }
            if(s[i] == '1'){
                one.pb(o-i+1);
            }else{
                zero.pb(o-i+1);
            }
            i = o;
        }
        ll ans = -1;
        ll s = 0,sum = 0;
        for(int i=0;i<sz(one);i++){
            s += (one[i] * a) + b;
            sum += one[i];
        }
        s+=((n-sum) * a) +b;
        ans = s;
        s = 0,sum = 0;
        for(int i=0;i<sz(zero);i++){
            s += (zero[i] * a) + b;
            sum += zero[i];
        }
        s+= ((n-sum) * a) + b;
        ans = max(ans,s);
        cout << max(ans,(ll)(a+b)*n)<<ln;
 
    }else{
        cout << (a + b)*n <<ln;
    }
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
