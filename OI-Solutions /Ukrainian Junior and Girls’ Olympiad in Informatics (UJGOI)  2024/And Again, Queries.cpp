#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 100 , LOG = 20;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , k , q;  cin >> n >> k >> q;
    vector <int> v(n) , nex(n + 1 , {});
    vector <vector <int>> anc(n + 1 , vector <int>(LOG , n));
    for(int i = 0 ; i < n ; i ++) cin >> v[i];
    map <int , int> cnt; int nx = 0;
    for(int i = 0 , j = 0 ; i < n ; i ++) {
        while( j <= n && nx <= k) {
            cnt[v[j]] ++ ;
            if(cnt[v[j]] == 1) nx ++ ; j ++ ;
        }
        anc[i][0] = j - 1;
        cnt[v[i]] -- ;
        if(cnt[v[i]] == 0) nx -- ;
    }
    for(int i = 1 ; i < LOG ; i ++) {
        for(int j = 0 ; j < n ; j ++) {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
    while(q --) {
        int l , r ; cin >> l >> r; -- l , -- r;
        int nx = l , res = 0;
        for(int i = LOG - 1 ; i >= 0 ; i --) {
            if(anc[nx][i] <= r) {
                nx = anc[nx][i];
                res += (1 << i);
            }
        }
        cout << res + 1 << '\n';
    }
}
