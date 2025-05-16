#include <bits/stdc++.h>
using namespace std;
 
#define all(c) begin(c), end(c)
#define pb push_back
 
using ll = long long;
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T --) {
        ll n ; cin >> n;
        priority_queue<int , vector <int> , greater <int>> pq;
        queue <int> q;
        for(int i = 0 ; i < n ; i ++) {
            ll x ; cin >> x;
            if(x == 1) {
                ll c; cin >> c;
                q.push(c);
            }else if(x == 2) {
                if(pq.size())  {
                    cout << pq.top() << '\n'; pq.pop();
                }else {
                    cout << q.front() << '\n'; q.pop();
                }
            }else {
                while(q.size()) {
                    pq.push(q.front()); q.pop();
                }
            }
        }
    }
    return 0;
}
