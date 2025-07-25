/*
  problem : Longest Good Segment - https://www.codechef.com/problems/LGSEG
*/
#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
using ll = long long;
const ll N = 1e6 + 100 , LOG = 27;
int anc[N][LOG];

int main(){
    // freopen("parachute.in", "r", stdin);
	// freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    ll tt = 1;
    cin >> tt; 
    while(tt--){
        int n , k , s , mx = 0; cin >> n >> k >> s;
        vector <int> v(n) , nex(n + 2 , {});
        for(int i = 0 ; i < n ; i ++) cin >> v[i];
        ll tot = 0;
        for(int i = 0 , j = 0 ; i < n ; i ++) {
            while (j < n && tot + v[j] <= s) {
                tot += v[j];
                ++j;
            }
            nex[i] = j;
            tot -= v[i];
        }
        // for(int i = 0 ; i < n ; i ++) cout << nex[i] << ' ';cout << '\n';
        for(int i = 0 ; i < n ; i ++) anc[i][0] = nex[i];
        for(int i = 1 ; i < LOG ; i ++){
            for(int j = 0 ; j < n ; j ++) {
                if(anc[j][i - 1] < n) anc[j][i] = anc[anc[j][i - 1]][i - 1];
                else anc[j][i] = n;
            }
        }

        for(int i = 0 ; i < n ; i ++) {
            int x = i;
            for(int j = 0 ; j < LOG ; j ++) {
                if((k >> j) & 1) {
                    x = anc[x][j];
                    if(x == n) break;
                } 
            }
            mx = max(mx , x - i);
        }
        cout << mx << '\n';
        for(int i = 0 ; i <= n + 50 ; i ++) {
            for(int j = 0 ; j < LOG ; j ++) {
                anc[i][j] = 0;
            }
        }
        // for(int i = 0 ; i < n ; i ++) cout << nex[i] << ' ';cout << '\n';
    }
    return 0;
}
