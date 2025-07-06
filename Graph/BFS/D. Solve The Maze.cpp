/* 
  problem : D. Solve The Maze - https://codeforces.com/contest/1365/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define pb push_back
const int N = 2e6 + 100;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt --) {
        int n , m , B = 0 , G = 0 ; cin >> n >> m;
        vector <vector <char>> v(n , vector <char>(m));
        for(int i = 0 ; i < n ; i ++) 
            for(int j = 0 ; j < m ; j ++)
                cin >> v[i][j] , G += (v[i][j] == 'G') , B += (v[i][j] == 'B');


        function <bool (int , int)> valid = [&](int i , int j) -> bool {
            return i >= 0 && i < n && j >= 0 && j < m;
        };    
        bool vis[n][m];
        memset(vis , 0 , sizeof vis);
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , -1 , 1};
        for(int i = 0 ; i < n ; i ++) {
            for(int j = 0 ; j < m ; j ++) {
                if(v[i][j] != 'B') continue;
                queue <pair <int , int>> q;
                q.push({i , j}); vis[i][j] = 1;
                vector <pair <int , int>> idx; idx.pb({i , j});
                while(q.size()) {
                    pair <int , int> p = q.front(); q.pop();
                    for(int k = 0 ; k < 4 ; k ++) {
                        int di = dx[k] + p.first , dj = dy[k] + p.second;
                        if(valid(di , dj) && v[di][dj] == 'B' && !vis[di][dj]) {
                            vis[di][dj] = 1;
                            idx.pb({di , dj});
                            q.push({di , dj});
                        }
                    }
                }
                for(auto [x , y] : idx) {
                    for(int k = 0 ; k < 4 ; k ++) {
                        int di = x + dx[k] , dj = y + dy[k];
                        if(valid(di , dj) && v[di][dj] == '.') {
                            v[di][dj] = 'W';
                        }
                    }
                }
            }
        }
        int dist[n][m];
        for(int i = 0 ; i < n ; i ++) for(int j = 0 ; j < m ; j ++) dist[i][j] = (int)1e9;
        if(v[ n - 1][m - 1] == '.' ) dist[n - 1][m - 1] = 0;
        int c = 0;
        if(dist[n - 1][m - 1] == 0){
            queue<pair<int,int>> q; q.push({n - 1 , m - 1});
            memset(vis , 0 , sizeof vis);
            vis[n - 1][m - 1] = 1;
            while(not q.empty()){
                pair <int , int> p = q.front(); q.pop();
                dist[p.first][p.second] = 0;
                if(v[p.first][p.second] == 'G') c ++ ;
                for(int k = 0 ; k < 4 ; k ++) {
                    int di = p.first + dx[k] , dj = p.second + dy[k];
                    if(valid(di , dj) && !vis[di][dj] && v[di][dj] != 'B' && v[di][dj] != 'W' && v[di][dj] != '#') {
                        vis[di][dj] = 1;
                        q.push({di , dj});
                    }
                }
            }
        }
        bool BcanReach = 0;
        for(int i = 0 ; i < n ; i ++) {
            for(int j = 0 ; j < m ; j ++) {
                if(v[i][j] != 'B') continue;
                for(int k = 0 ; k < 4 ; k ++) {
                    int di = i + dx[k] , dj = j + dy[k];
                    if(valid(di , dj) && dist[di][dj] == 0) BcanReach = 1;
                } 
            }
        }
        if(c == G && !BcanReach) cout << "Yes\n";
        else cout << "No\n";
    }   
    return 0;
}
 
