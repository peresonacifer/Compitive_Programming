#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
typedef pair<int, int> pii;
#define rep(i,n) for(i64 i=0; i<i64(n); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define F first
#define S second
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }

void sol() {
    unordered_map<int, unordered_set<int>> mp;
    int n, m, q;
    cin >> n >> m >> q;
    rep(i, q) {
        int c, x;
        cin >> c >> x;
        if(c == 1) {
            int y;
            cin >> y;
            mp[x].insert(y); 
        }
        else if(c == 2) {
            mp[x].insert(-1);
        }
        else {
            int y;
            cin >> y;
            if(mp.find(x) == mp.end() || (mp[x].find(y) == mp[x].end() && mp[x].find(-1) == mp[x].end())) {
                cout << "No\n";
            }
            else cout << "Yes\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    // cin >> T; 
    rep(i, T) sol();
    return 0;
}