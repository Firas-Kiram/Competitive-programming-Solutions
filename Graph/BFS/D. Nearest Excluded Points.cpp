#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;

const ll N = 1e6 + 100;

int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};
vector <pair<int,int>> v;
map <pair <int , int> , bool> vis ;
map <pair <int , int> , int> dist;
map <pair <int , int> , pair <int , int>> res;
queue <pair <int , int>> q;

bool valid(int i , int j) {
    int m = 1e6; return i >= -m && i <= m && j >= -m && j <= m;
}

int calc(int x , int y , int xx , int yy) {
    return abs(x - xx) + abs(y - yy);
}

bool work(int i , int j){
    bool ok = 0;
    for(int k = 0 ; k < 8 ; k ++) {
        int di = dx[k] + i;
        int dj = dy[k] + j;
        if(!vis[{di , dj}]) {
            if(dist[{i , j}] > calc(i , j , di , dj)){
                dist[{i , j}] = calc(i , j , di , dj);
                res[{i , j}] = {di , dj};
                // cout << di << ' ' << dj << ' ' << i << ' ' << j << '\n';
                ok = 1;
            }
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int tt = 1;
    // cin  >> tt; 
    while(tt--) {
        int n; cin >> n;
        v = vector <pair <int,int>>(n);
        // queue <tuple <int , int , int>> q;
        for(int i = 0 ; i < n ; i ++ ) {
            cin >> v[i].first >> v[i].second;
            vis[{v[i].first , v[i].second}] = 1;
            dist[{v[i].first , v[i].second}] = 1e8;
            // q.push({v[i].first , v[i].second , i});
        }

        for(int i = 0 ; i < n ; i ++) {
            if(work(v[i].first , v[i].second))
                q.push({v[i].first , v[i].second});
            
        }
        
        while(q.size()) {
            pair <int , int> p = q.front(); q.pop();
            int a = p.first , b = p.second;
            for(int k = 0 ; k < 8 ; k ++) {
                int di = a + dx[k] , dj = b + dy[k];
                if(valid(di , dj) && vis[{di , dj}]) {
                    int nx =  dist[{a , b}] + calc(a , b , di , dj);
                    if(dist[{di , dj}] > nx) {
                        dist[{di , dj}] = nx;
                        q.push({di , dj});
                        res[{di , dj}] = res[{a , b}];
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i ++) {
            auto &to = res[{v[i].first , v[i].second}];
            cout << to.first << ' ' << to.second << '\n';
        }
    }   
    return 0;
}
