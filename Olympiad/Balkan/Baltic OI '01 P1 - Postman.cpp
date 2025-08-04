#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
using ll = long long;

vector <vector <pair <int , int>>> edj;
vector <bool> vis;
vector <int> ans , w;

void dfs(int node) {
	while(edj[node].size()) {
		auto [u , idx] = edj[node].back();
		edj[node].pop_back();
		if(vis[idx]) continue;
		vis[idx] = 1;
		dfs(u);
	}
	ans.pb(node);
}

int main() {
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	while(tt --) {
		int n , m ; cin >> n >> m;
		w.assign(n + 100 , {});
		vis.assign(m + 5 , false);
		edj.resize(n + 5);
		for(int i = 1 ; i <= n ; i ++) cin >> w[i];
		for(int i = 0 ; i < m ; i ++) {
			int u , v ; cin >> u >> v;
			edj[u].pb({v , i}); edj[v].pb({u , i});
		}
		dfs(1);
		cout << ans.size() - 1 << '\n';
		for(auto to : ans) cout << to << ' ';cout << '\n';
	}
	
	return 0;
}
