/**
 *    author:  firas kiram (corvus)
**/
#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;
vector <ll> spf , a;

void prepa() {
  int n = 1e7 + 1e6 + 100;
  spf = vector <ll> (n + 1 , {});
  for(int i = 2 ; i <= n ; i ++) {
    if(spf[i]) continue;
    for(int j = i + i ; j <= n ; j += i) spf[j] = i;
  }
  spf[1] = 1;
  for(int i = 2 ; i <= n && (int)a.size() <= 2000002 ; i ++) {
    if(spf[i] && (i / spf[i]) != spf[i] && !spf[spf[i]] && !spf[i / spf[i]]) a.pb(i);
  }
  sort(all(a));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    prepa();
    cin >> tt;
    while(tt--) {
      int k ; cin >> k;
      cout << a[k - 1] << '\n';
    }

    return 0;
}    
