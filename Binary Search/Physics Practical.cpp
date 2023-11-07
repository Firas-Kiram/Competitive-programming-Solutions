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
int n,k;

bool good(int x,vector <int>&v){
    int k = x;
    if((v[x]*2)>=v[sz(v)-1]){
        return 1;
    }else if(v[sz(v)-1-x] <= v[0]*2){
        return 1;
    }else{
        int p = 0;
        while(p!=k){
            if(v[p]*2>=v[n - 1 - x]){
                return 1;
            }
            p++;
            x--;
        }
    }
    return 0;
}


void solve(){
    cin >>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    sort(all(v));
    int l = 0,r = n-1,ans = 0;
    while(l<=r){
        int md = (l+r)/2;
        if(good(md,v)){
            r = md-1;
            ans = md;
        }else{
            l = md+1;
        }   
    }
    cout << ans << ln;
}


int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
