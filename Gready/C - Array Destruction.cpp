#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;


multiset <ll> s;
vector < int > v;
int n;
void work(int x) {
    for(int i = 1 ; i < n ; i ++) {
        if(i == x) continue;
        s.insert(v[i]);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T --) {
        cin >> n; n *= 2;
        v.resize(n);
        for(int i = 0 ; i < n ; i ++) cin >> v[i];
        sort(all(v) , greater <int>());
        bool found = 0;
        for(int i = 1 ; i < n && !found ; i ++) {
            ll tot = v[0] , idx = 0 , cnt = n - 2 , op = (n - 2) / 2;
            vector <pair <int , int>> ans; ans.pb({v[0] , v[i]}); s.clear(); work(i);
            if(cnt == 0) {
                cout << "YES\n";
                cout << ans[0].first + ans[0].second << '\n';
                for(auto it : ans) cout << it.first << ' ' << it.second << '\n';
                found = 1;
            }
            while(op -- && s.size() && !found) {
                auto it = --s.end();
                ll val = tot - *it;
                auto itt = s.find(val);
                if(itt != s.end() && itt != it) {
                    tot = max(*itt , *it); ans.pb({*itt , *it}); 
                    s.erase(itt); s.erase(--s.end());  cnt -= 2;
                }else break;
                if(cnt == 0) {
                    cout << "YES\n";
                    cout << ans[0].first + ans[0].second << '\n';
                    for(auto it : ans) cout << it.first << ' ' << it.second << '\n';
                    found = 1;
                }
            }
        }
        if(!found) cout << "NO\n";
    }
    return 0;
}
