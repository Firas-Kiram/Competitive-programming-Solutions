/*
  problem : Balkan OI '11 P3 - Medians - https://dmoj.ca/problem/bkoi11p3
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 100;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        int n; cin >> n;
        vector <int> v(n) , res(n * 2 - 1 , {});
        for(int i = 0 ; i < n ; i ++) cin >> v[i];
        vector <bool> vis(n * 2 + 1 , false);
        int r = n * 2 - 1 , l = 1;
        res[0] = v[0]; vis[v[0]] = 1; int idx = 1;
        function < void (int& , int&)> next = [&] (int& l , int& r) {
            while(r >= 1 && vis[r]) r -- ;
            while(l < 2 * n && vis[l]) l ++ ;
        };

        for(int i = 1 ; i < n ; i ++) {
            int idx = ((i + 1) * 2) - 1;
            if(v[i] == v[i - 1]) {
                vis[r] = 1;
                res[idx - 1] = r;
                next(l , r);
                vis[l] = 1;
                res[idx - 2] = l;
                next(l , r);
            }else if(v[i] > v[i - 1]) {
                if(!vis[v[i]]) {
                    res[idx - 1] = v[i];
                    vis[v[i]] = 1;
                    next(l , r);
                    vis[r] = 1;
                    res[idx - 2] = r;
                    next(l , r);
                }else{
                    vis[r] = 1;
                    res[idx - 1] = r;
                    next(l , r);
                    vis[r] = 1;
                    res[idx - 2] = r;
                    next(l , r);
                }
            }else if(v[i] < v[i - 1]) {
                if(!vis[v[i]]) {
                    vis[v[i]] = 1;
                    res[idx - 1] = v[i];
                    next(l , r);
                    vis[l] = 1;
                    res[idx - 2] = l;
                    next(l , r);
                }else {
                    vis[l] = 1;
                    res[idx - 1] = l;
                    next(l , r);
                    vis[l] = 1;
                    res[idx - 2] = l;
                    next(l , r);
                }
            }
        }

        for(int i = 0 ; i < res.size() ; i ++) cout << res[i] << ' ';cout << '\n';
    }   
    return 0;
}
 
